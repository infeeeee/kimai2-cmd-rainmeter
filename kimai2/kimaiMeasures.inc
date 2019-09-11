; -------------------------------------------------------------------------- 
;                                  MEASURES                                  
; -------------------------------------------------------------------------- 

[MeasureStart]
Measure=Plugin
Plugin=RunCommand
Program=#kimaiExe#
Parameter=restart #measurementid#
StartInFolder=#kimaiDir#
DynamicVariables=1
FinishAction=[!CommandMeasure MeasureReload "Run"]
State=Hide

; Uncomment for logging
; OutputFile=#CURRENTPATH#log.txt
; OutputType=UTF8

[MeasureStop]
Measure=Plugin
Plugin=RunCommand
Program=#kimaiExe#
Parameter=stop
StartInFolder=#kimaiDir#
FinishAction=[!SetVariable stopHidden 1][!SetVariable startHidden 0][!CommandMeasure MeasureReload "Run"]
State=Hide

; Uncomment for logging
; OutputFile=#CURRENTPATH#log.txt
; OutputType=UTF8

[MeasureReload]
Measure=Plugin
Plugin=RunCommand
Program=#kimaiExe#
Parameter=rainmeter
StartInFolder=#kimaiDir#
FinishAction=[!Refresh]
State=Hide

; Uncomment for logging
; OutputFile=#CURRENTPATH#log.txt
; OutputType=UTF8

[MeasureFirstrun]
Measure=Plugin
Plugin=RunCommand
Parameter=start "" #kimaiExe#
StartInFolder=#kimaiDir#
State=Show

; Uncomment for logging
; OutputFile=#CURRENTPATH#log.txt
; OutputType=UTF8