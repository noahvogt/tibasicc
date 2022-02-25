@echo off

:: create binary directory if needed
if not exist "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" (
	mkdir "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" || goto adminError
	echo folder "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" has been created.
)
:: add g++ to path variable (only in this session)
set PATH=%PATH%;C:\MinGW\bin\

:: compiling
echo g++ -g -Wall -pedantic  -c -o src/compiler.o src/compiler.cc
g++ -g -Wall -pedantic  -c -o src/compiler.o src/compiler.cc || goto compileError
echo g++ -g -Wall -pedantic   -c -o src/token_util.o src/token_util.cc
g++ -g -Wall -pedantic   -c -o src/token_util.o src/token_util.cc || goto compileError
echo g++ -g -Wall -pedantic   -c -o src/main.o src/main.cc
g++ -g -Wall -pedantic   -c -o src/main.o src/main.cc || goto compileError
echo g++ -o tibasicc src/compiler.o src/token_util.o src/main.o
g++ -o tibasicc src/compiler.o src/token_util.o src/main.o

:: move executable to the final directory
copy tibasicc.exe "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" || goto movingError

goto success

:adminError
echo.
echo Error: 	TI-Basic couldn't be installed. 
echo        	Make sure to run this program with admin privileges.
echo.
exit

:compileError
echo.
echo Error:		TI-Basic couldn't be installed.
echo			Compiling with g++ failed. Make sure that it is installed correctly.
echo.
exit

:movingError
echo.
echo Error:		TI-Basic couldn't be installed.
echo			Moving the binary to your program files failed. Make sure that you have appropriate permissions to this directory.
echo.
exit

:success
echo.
echo.
echo.
echo 	tibasicc has been successfully installed.
echo 	But now you need to add "%HOMEDRIVE%\MinGW\bin" and "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin"
echo	........to your Path variable manually (sorry, but this just is how Windows works).
echo.
pause
