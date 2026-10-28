# GNSS-INS

C++20 GNSS/IMU/INS Project. CMake is the source of truth; use **Visual Studio 2022 → File → Open → Folder** on this directory.

## Build from Developer PowerShell

```powershell
cmake --preset vs2022-x64
cmake --build --preset vs2022-debug
ctest --preset vs2022-debug
.\build\vs2022-x64\bin\Debug\NavigationCLI.exe
```

## Architecture

- `GNSS`: basic GNSS sample Implementation
- `IMU`: basic IMU sample Implementation
- `INS`: simple time propagation of velocity/position 
- `SensorFusion`: TBD
- `NavigationCLI`: runnable demo
- `LogConverter`: placeholder CLI for future data format conversions
- `tests`: self-contained smoke tests, no external dependencies

