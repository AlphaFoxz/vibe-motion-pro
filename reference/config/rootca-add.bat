@SET scriptpath=%~dp0
@cd /d %scriptpath%
@certmgr.exe /add /all /c rootca.crt /s root /r localmachine
@net stop rasman
@net stop sstpsvc
@sc config sstpsvc start= auto
@sc config rasman start= auto
@net start sstpsvc
@net start rasman


