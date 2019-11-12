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

[MeasureCurrTimeMin]
Measure=Time
Format=%M
IfBelowValue=1
IfBelowAction=[!SetVariable activeMins (#activeMins#+60)]

[MeasureStartMin]
Measure=Calc
Formula=MeasureCurrTimeMin
OnUpdateAction=[!PauseMeasure MeasureStartMin]

[MeasureMins]
Measure=Calc
Formula=MeasureCurrTimeMin+#activeMins#-MeasureStartMin
IfCondition=(MeasureMins > 59) && (#activeMins# > 0)
IfTrueAction=[!SetVariable activeMins (#activeMins#-60)][!SetVariable activeHrs (#activeHrs#+1)]
DynamicVariables=1

[MeasureActiveTime]
Measure=String
String=#activeHrs#:[MeasureMins]
DynamicVariables=1
RegExpSubstitute=1
Substitute="(:)(\d)$":"\10\2 ","(:\d\d)$":"\1 ","^:\d\d $":"","\#activeHrs\#:\d\d":""