@echo off
echo 正在拉取远程最新代码，防止冲突...
git.exe pull --rebase

echo.
set /p msg=请输入提交信息:
if "%msg%"=="" (
  echo 提交信息不能为空，脚本结束。
  pause
  exit /b
)

echo 正在添加更改...
git.exe add .

echo 正在提交...
git.exe commit -m "%msg%"

echo 正在推送代码到当前分支...
git.exe push
pause