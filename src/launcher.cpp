
#include <windows.h>
#include <shellapi.h>
#include <filesystem>
#include <string>

int WINAPI wWinMain(
    HINSTANCE,
    HINSTANCE,
    PWSTR,
    int
) {
    wchar_t buffer[MAX_PATH];

    DWORD length = GetModuleFileNameW(
        nullptr, buffer, MAX_PATH
    );

    if (length == 0 || length >= MAX_PATH) {
        MessageBoxW(
            nullptr,
            L"Unable to locate the launcher.",
            L"Engineering Workbench",
            MB_OK | MB_ICONERROR
        );
        return 1;
    }

    std::filesystem::path exePath(buffer);
    std::filesystem::path appDir = exePath.parent_path();

    std::filesystem::path dashboard =
        appDir / L"frontend" / L"index.html";

    if (!std::filesystem::exists(dashboard)) {
        MessageBoxW(
            nullptr,
            L"Dashboard not found.\n"
            L"Make sure the frontend folder is beside Launch.exe.",
            L"Engineering Workbench",
            MB_OK | MB_ICONERROR
        );
        return 1;
    }

    auto result = reinterpret_cast<INT_PTR>(
        ShellExecuteW(
            nullptr,
            L"open",
            dashboard.c_str(),
            nullptr,
            appDir.c_str(),
            SW_SHOWNORMAL
        )
    );

    if (result <= 32) {
        MessageBoxW(
            nullptr,
            L"Unable to open the dashboard.",
            L"Engineering Workbench",
            MB_OK | MB_ICONERROR
        );
        return 1;
    }

    return 0;
}
