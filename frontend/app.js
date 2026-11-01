
/* =========================================
   1. Page navigation
========================================= */

const pages = document.querySelectorAll(".page");
const navButtons = document.querySelectorAll("nav button");
const heading = document.querySelector("#heading");

function showPage(pageId) {
    pages.forEach((page) => {
        page.classList.toggle("show", page.id === pageId);
    });

    navButtons.forEach((button) => {
        const isActive = button.dataset.page === pageId;

        button.classList.toggle("active", isActive);
    });

    const selectedButton = document.querySelector(
        `nav button[data-page="${pageId}"]`
    );

    heading.textContent = selectedButton
        ? selectedButton.textContent.trim().replace(/^\d+/, "").trim()
        : "Overview";
}

navButtons.forEach((button) => {
    button.addEventListener("click", () => {
        showPage(button.dataset.page);
    });
});

document.querySelectorAll("[data-go]").forEach((button) => {
    button.addEventListener("click", () => {
        showPage(button.dataset.go);
    });
});


/* =========================================
   2. Thermal FEM convergence data
========================================= */

const meshResults = [
    { elements: 10, error: 1.25 },
    { elements: 20, error: 0.3125 },
    { elements: 40, error: 0.078125 },
    { elements: 80, error: 0.01953125 }
];

const meshTable = document.querySelector("#mesh");

meshTable.innerHTML = meshResults.map((result) => {
    return `
        <tr>
            <td>${result.elements}</td>
            <td>${result.error}</td>
        </tr>
    `;
}).join("");


/* =========================================
   3. Thermal convergence chart
========================================= */

function drawThermalChart() {
    const canvas = document.querySelector("#thermalChart");

    if (!canvas) {
        return;
    }

    const ctx = canvas.getContext("2d");

    const width = canvas.width;
    const height = canvas.height;

    const margin = {
        top: 25,
        right: 30,
        bottom: 55,
        left: 75
    };

    const plotWidth = width - margin.left - margin.right;
    const plotHeight = height - margin.top - margin.bottom;

    ctx.clearRect(0, 0, width, height);

    ctx.font = "12px Segoe UI, Arial";
    ctx.lineWidth = 1;

    const maxLog = Math.log10(2);
    const minLog = Math.log10(0.01);

    function getX(index) {
        return margin.left +
            (index / (meshResults.length - 1)) * plotWidth;
    }

    function getY(error) {
        const value = Math.log10(error);

        return margin.top +
            ((maxLog - value) / (maxLog - minLog)) * plotHeight;
    }

    /* Horizontal grid lines */

    const yTicks = [1, 0.1, 0.01];

    yTicks.forEach((tick) => {
        const y = getY(tick);

        ctx.beginPath();
        ctx.strokeStyle = "#e5e9ee";
        ctx.moveTo(margin.left, y);
        ctx.lineTo(width - margin.right, y);
        ctx.stroke();

        ctx.fillStyle = "#788697";
        ctx.textAlign = "right";
        ctx.fillText(tick.toString(), margin.left - 12, y + 4);
    });

    /* Vertical axis */

    ctx.beginPath();
    ctx.strokeStyle = "#aeb9c4";
    ctx.moveTo(margin.left, margin.top);
    ctx.lineTo(margin.left, height - margin.bottom);
    ctx.stroke();

    /* Horizontal axis */

    ctx.beginPath();
    ctx.moveTo(margin.left, height - margin.bottom);
    ctx.lineTo(width - margin.right, height - margin.bottom);
    ctx.stroke();

    /* Draw convergence line */

    ctx.beginPath();
    ctx.strokeStyle = "#416b98";
    ctx.lineWidth = 2.5;

    meshResults.forEach((result, index) => {
        const x = getX(index);
        const y = getY(result.error);

        if (index === 0) {
            ctx.moveTo(x, y);
        } else {
            ctx.lineTo(x, y);
        }
    });

    ctx.stroke();

    /* Draw data points and labels */

    meshResults.forEach((result, index) => {
        const x = getX(index);
        const y = getY(result.error);

        ctx.beginPath();
        ctx.fillStyle = "#ffffff";
        ctx.strokeStyle = "#416b98";
        ctx.lineWidth = 2;

        ctx.arc(x, y, 5, 0, Math.PI * 2);

        ctx.fill();
        ctx.stroke();

        ctx.fillStyle = "#526579";
        ctx.textAlign = "center";

        ctx.fillText(
            result.elements.toString(),
            x,
            height - margin.bottom + 22
        );

        ctx.fillText(
            result.error.toString(),
            x,
            y - 12
        );
    });

    /* Axis labels */

    ctx.fillStyle = "#657487";
    ctx.textAlign = "center";

    ctx.fillText(
        "Number of elements",
        width / 2,
        height - 12
    );

    ctx.save();

    ctx.translate(18, height / 2);
    ctx.rotate(-Math.PI / 2);

    ctx.fillText(
        "Midpoint error (°C, logarithmic scale)",
        0,
        0
    );

    ctx.restore();
}


/* =========================================
   4. Initialisation
========================================= */

drawThermalChart();

showPage("overview");
