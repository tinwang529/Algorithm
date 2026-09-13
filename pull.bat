@echo off
:: 切换到脚本所在目录（防止在子目录运行出错）
cd /d "%~dp0"

echo ====================================================
echo        正在同步远程仓库到本地 (安全模式)
echo ====================================================

:: 1. 获取当前分支名
for /f "tokens=*" %%i in ('git branch --show-current') do set branch=%%i
if "%branch%"=="" (
    echo [错误] 无法检测当前分支，请确保您在 Git 仓库中。
    pause
    exit /b
)
echo [1/2] 当前分支: %branch%

:: 2. 拉取远程更新
::    --rebase    保留你本地的提交，把它们重放到远程更新之上
::    --autostash 自动暂存未提交的改动，拉取后自动恢复
echo [2/2] 正在拉取远程更新（rebase + 自动暂存）...
git pull --rebase --autostash

echo.
echo 同步完成！远程更新已合并，本地改动已保留。
pause
