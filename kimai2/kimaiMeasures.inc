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

; [MeasureDuration]
; Measure=String
; Formula=#activeRecording#
; IfMatch=No active recording
; IfMatchAction=[!SetVariable activeDur '']
; IfNotMatchAction=[!SetVariable activeDur (MeasureHrs + : + MeasureMins)]


; [MeasureHrs]
; Measure=Calc
; Formula=#activeHrs#+MeasureHrs+1%25

; [MeasureMins]
; Measure=Calc
; Formula=MeasureMins >= 0 ? (MeasureMins+1%60) : #activeMins#
; UpdateDivider=60
; IfCondition=MeasureMins = 60
; IfTrueAction=[!SetVariable #activeHrs# (#activeHrs#+1)]
