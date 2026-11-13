@SET scriptpath=%~dp0
@cd /d %scriptpath%
@certmgr.exe /add /all /c CA_cert.crt /s root /r localmachine


