# Embedded integration design (simulated)

## Block-level architecture

```text
                 USB CDC / serial telemetry
[Host PC] ------------------------------------ [MCU board]
    |
    | USB host link
    v
[JTAG adapter] ===== TCK / TMS / TDI / TDO ===== [FPGA board]
    |
    +---- C++ host-side adapter / discovery / capability layer

All behaviour in this prototype is mocked. No physical device is connected.
```

## Interface and pin-voltage assumptions

| Connection | Signals / pins | Voltage assumption | Notes |
|---|---|---|---|
| Host to MCU | USB D+/D-, VBUS, GND | USB 5 V VBUS; MCU I/O 3.3 V | USB CDC telemetry; board regulates its own logic rail |
| MCU GPIO | UART TX/RX, GPIO, GND | 3.3 V logic | Never apply 5 V logic unless the exact board pin is documented as tolerant |
| Host to JTAG adapter | USB | USB 5 V bus power | Adapter-specific; use its datasheet and target reference voltage |
| JTAG adapter to FPGA | TCK, TMS, TDI, TDO, GND, VTref | Assumed 3.3 V bank in this example | Verify the FPGA board's actual JTAG header and bank voltage before connection |
| Power | Board-specific supply input | Board-specific | Do not power boards through signal pins; avoid competing supplies |
| Ground | Signal ground reference | Common reference | Connect grounds as required by adapter/target documentation |

The table is an illustrative design assumption, not a verified pinout for every board revision. Confirm exact connector orientation, pin numbering, voltage tolerance, VTref behaviour and power requirements from the selected board and adapter manuals before wiring.

## JTAG ownership

The host controls the USB-JTAG adapter. The adapter drives TCK, TMS and TDI toward the FPGA and samples TDO. The FPGA is the JTAG target. The MCU is a separate host-connected device and does not become a JTAG adapter or interchangeable compute board.

A JTAG adapter is a debug/programming transport interface. It does not provide general-purpose application compute resources. The mock C++ layer implements discovery, capability reporting, connect/disconnect state and telemetry/timeout demonstration only.
