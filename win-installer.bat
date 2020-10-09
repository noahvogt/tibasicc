@echo off

:: create binary directory if needed
if not exist "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" (
	mkdir "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" || goto adminError
	echo folder "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" has been created.
)
:: add g++ to path (only in this session)
set PATH=%PATH%;C:\MinGW\bin\


:: compiling
echo g++ -g -Wall -pedantic  -c -o src/main.o src/main.cpp
g++ -g -Wall -pedantic  -c -o src/main.o src/main.cpp || goto compileError
echo g++ -g -Wall -pedantic   -c -o src/tokens.o src/tokens.cpp
g++ -g -Wall -pedantic   -c -o src/tokens.o src/tokens.cpp || goto compileError
echo g++ -g -Wall -pedantic   -c -o src/tibasic.o src/tibasic.cpp
g++ -g -Wall -pedantic   -c -o src/tibasic.o src/tibasic.cpp || goto compileError
echo g++ -o tibasicc src/main.o src/tibasic.o src/tokens.o
g++ -o tibasicc src/main.o src/tibasic.o src/tokens.o

:: move executable to the final directory
copy tibasicc.exe "%HOMEDRIVE%\Program Files (x86)\tibasicc\bin" || goto unknownError

goto success

:adminError
echo.
echo Error: 	TI-Basic could'nt be installed. 
echo        	Make sure to run this programm with admin privileges.
echo.
exit

:compileError
echo.
echo Error:		TI-Basic could'nt be installed.
echo			Compiling with g++ failed. Make sure that it is installed correctly.
echo.
exit

:unknownError
echo.
echo Error:		TI-Basic could'nt be installed.
echo			Compiling with g++ failed. Make sure that it is installed correctly.
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