4d-plugin-ical
==============

4D plugin to access to the CalendarStore API (10.5 to 10.7). For 10.8 and Reminders, use Event Kit.

##Platform

| carbon | cocoa | win32 | win64 |
|:------:|:-----:|:---------:|:---------:|
|🆗|🚫|🚫|🚫|

Commands
---

```c
// --- Type Cast
iCal_Make_date
iCal_GET_DATE
iCal_Make_color
iCal_GET_COLOR
iCal_Make_color_from_index

// --- Timezone
iCal_TIMEZONE_LIST
iCal_Get_timezone_info
iCal_Get_timezone_for_offset
iCal_Get_system_timezone

// --- Task
iCal_Create_task
iCal_Set_task_property
iCal_Get_task_property
iCal_Remove_task
iCal_Count_task_alarms
iCal_Get_task_alarm
iCal_Remove_task_alarm
iCal_Set_task_alarm

// --- Event
iCal_Create_event
iCal_Set_event_property
iCal_Get_event_property
iCal_Remove_event
iCal_Get_event_alarm
iCal_Count_event_alarms
iCal_Remove_event_alarm
iCal_Set_event_alarm
iCal_Set_event_properties

// --- Recurrence Rule
iCal_Remove_event_recurrence
iCal_Set_event_recurrence

// --- Calendar Store
iCal_QUERY_EVENT
iCal_GET_CALENDAR_LIST
iCal_QUERY_TASK

// --- Calendar
iCal_Create_calendar
iCal_Set_calendar_property
iCal_Get_calendar_property
iCal_Remove_calendar

// --- Application
iCal_TERMINATE
iCal_LAUNCH

// --- iCal Direct
iCal_SHOW_EVENT(PA_PluginParameters params);
iCal_SHOW_TASK(PA_PluginParameters params);
iCal_SET_VIEW(PA_PluginParameters params);
iCal_SHOW_DATE(PA_PluginParameters params);
iCal_app_Get_task_property
iCal_app_Get_event_property

// --- Alarm
iCal_Make_alarm
iCal_Get_alarm_property
iCal_Set_alarm_property
iCal_Add_alarm_to_event
iCal_Add_alarm_to_task
```
