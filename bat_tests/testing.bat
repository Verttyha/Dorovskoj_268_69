@echo off
cd /d %~dp0
>results.txt echo.

for /L %%i in (1,1,50) do (
    echo Тест %%i>>results.txt
    SearchMatrixIdenticalElements.exe inputs\input_%%i.txt tmp_output.txt
    if not exist output\output_%%i.txt (
        echo Эталонного файла output\output_%%i.txt нет>>results.txt
    ) else (
        fc /W tmp_output.txt output\output_%%i.txt >nul
        if errorlevel 1 (
            echo Не пройден>>results.txt
            echo Входные данные:>>results.txt
            type inputs\input_%%i.txt>>results.txt
            echo Получено:>>results.txt
            type tmp_output.txt>>results.txt
            echo Ожидалось:>>results.txt
            type output\output_%%i.txt>>results.txt
        ) else (
            echo Пройден>>results.txt
        )
    )
    echo.>>results.txt
)

del tmp_output.txt
