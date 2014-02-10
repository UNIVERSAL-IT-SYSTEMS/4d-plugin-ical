/* --------------------------------------------------------------------------------
 #
 #	4DPlugin.c
 #	source generated by 4D Plugin Wizard
 #	Project : iCal
 #	author : miyako
 #	11/07/08
 #
 # --------------------------------------------------------------------------------*/


#include "4DPlugin.h"

#include "ical_listener.h"
#include "ical_tools.h"
#include "ical_alarm.h"
#include "ical_calendar.h"
#include "ical_calendar_store.h"
#include "ical_timezome.h"
#include "ical_application.h"
#include "ical_event.h"
#include "ical_task.h"

namespace iCal
{
    iCalListener *listener = nil;
};

void PluginMain(int32_t selector, PA_PluginParameters params)
{
	try
	{
		int32_t pProcNum = selector;
		sLONG_PTR *pResult = (sLONG_PTR *)params->fResult;
		PackagePtr pParams = (PackagePtr)params->fParameters;

		switch(selector)
		{
			case 30 :
				PA_RunInMainProcess((PA_RunInMainProcessProcPtr)iCal_SHOW_EVENT, params);
				break;
				
			case 31 :
				PA_RunInMainProcess((PA_RunInMainProcessProcPtr)iCal_SHOW_TASK, params);
				break;
				
			case 32 :
				PA_RunInMainProcess((PA_RunInMainProcessProcPtr)iCal_SET_VIEW, params);
				break;
				
			case 33 :
				PA_RunInMainProcess((PA_RunInMainProcessProcPtr)iCal_SHOW_DATE, params);
				break;	
				
			case 34 :
				PA_RunInMainProcess((PA_RunInMainProcessProcPtr)iCal_app_Get_task_property, params);	
				break;
				
			case 35 :
				PA_RunInMainProcess((PA_RunInMainProcessProcPtr)iCal_app_Get_event_property, params);
				break;				
				
			default:
				CommandDispatcher(pProcNum, pResult, pParams); 
				break;
		}
		
	}
	catch(...)
	{

	}
}

void CommandDispatcher (int32_t pProcNum, sLONG_PTR *pResult, PackagePtr pParams)
{	
	switch(pProcNum)
	{				
		case kDeinitPlugin:
		case kServerDeinitPlugin:
			listenerLoopFinish();
			break;			
			
		case kInitPlugin:
		case kServerInitPlugin:
			break;	
			
			// --- Event
			
		case 1 :
			iCal_Create_event(pResult, pParams);
			break;
			
		case 2 :
			iCal_Set_event_property(pResult, pParams);
			break;
			
		case 3 :
			iCal_Get_event_property(pResult, pParams);
			break;
			
		case 4 :
			iCal_Remove_event(pResult, pParams);
			break;
			
			// --- Task
			
		case 5 :
			iCal_Create_task(pResult, pParams);
			break;
			
		case 6 :
			iCal_Set_task_property(pResult, pParams);
			break;
			
		case 7 :
			iCal_Get_task_property(pResult, pParams);
			break;
			
		case 8 :
			iCal_Remove_task(pResult, pParams);
			break;
			
			// --- Calendar
			
		case 9 :
			iCal_Create_calendar(pResult, pParams);
			break;
			
		case 10 :
			iCal_Set_calendar_property(pResult, pParams);
			break;
			
		case 11 :
			iCal_Get_calendar_property(pResult, pParams);
			break;
			
		case 12 :
			iCal_Remove_calendar(pResult, pParams);
			break;
			
			// --- Calendar Store
			
		case 13 :
			iCal_QUERY_EVENT(pResult, pParams);
			break;
			
		case 14 :
			iCal_GET_CALENDAR_LIST(pResult, pParams);
			break;
			
		case 15 :
			iCal_QUERY_TASK(pResult, pParams);
			break;
			
			// --- Type Cast
			
		case 16 :
			iCal_Make_date(pResult, pParams);
			break;
			
		case 17 :
			iCal_GET_DATE(pResult, pParams);
			break;
			
		case 18 :
			iCal_Make_color(pResult, pParams);
			break;
			
		case 19 :
			iCal_GET_COLOR(pResult, pParams);
			break;
			
		case 20 :
			iCal_Make_color_from_index(pResult, pParams);
			break;
			
			// --- Recurrence Rule
			
		case 21 :
			iCal_Remove_event_recurrence(pResult, pParams);
			break;
			
		case 22 :
			iCal_Set_event_recurrence(pResult, pParams);
			break;
			
			// --- Alarm
			
		case 23 :
			iCal_Make_alarm(pResult, pParams);
			break;
			
		case 24 :
			iCal_Get_alarm_property(pResult, pParams);
			break;
			
		case 25 :
			iCal_Set_alarm_property(pResult, pParams);
			break;
			
		case 26 :
			iCal_Add_alarm_to_event(pResult, pParams);
			break;
			
		case 27 :
			iCal_Add_alarm_to_task(pResult, pParams);
			break;
			
			// --- Application
			
		case 28 :
			iCal_TERMINATE(pResult, pParams);
			break;
			
		case 29 :
			iCal_LAUNCH(pResult, pParams);
			break;
									
			// --- Notification
			
		case 36 :
			iCal_Set_notification_method(pResult, pParams);
			break;
			
		case 37 :
			iCal_Get_notification_method(pResult, pParams);
			break;
			
			// --- Alarm II
			
		case 38 :
			iCal_Get_event_alarm(pResult, pParams);
			break;
			
		case 39 :
			iCal_Count_event_alarms(pResult, pParams);
			break;
			
		case 40 :
			iCal_Remove_event_alarm(pResult, pParams);
			break;
			
		case 41 :
			iCal_Set_event_alarm(pResult, pParams);
			break;
			
		case 42 :
			iCal_Count_task_alarms(pResult, pParams);
			break;
			
		case 43 :
			iCal_Get_task_alarm(pResult, pParams);
			break;
			
		case 44 :
			iCal_Remove_task_alarm(pResult, pParams);
			break;
			
		case 45 :
			iCal_Set_task_alarm(pResult, pParams);
			break;
			
			// --- Timezone
			
		case 46 :
			iCal_TIMEZONE_LIST(pResult, pParams);
			break;
			
		case 47 :
			iCal_Get_timezone_info(pResult, pParams);
			break;
			
		case 48 :
			iCal_Get_timezone_for_offset(pResult, pParams);
			break;
			
		case 49 :
			iCal_Get_system_timezone(pResult, pParams);
			break;			
	}

}

#pragma mark -

void listenerLoopExecuteMethodByID()
{
	PA_Variable	params[4];
	params[0] = PA_CreateVariable(eVK_Unistring);		
	params[1] = PA_CreateVariable(eVK_Unistring);	
	params[2] = PA_CreateVariable(eVK_Unistring);					
	params[3] = PA_CreateVariable(eVK_Unistring);	
	
	PA_Unistring u1 = PA_setUnistringVariable(&params[0], iCal::listener.insertedRecordsString);
	PA_Unistring u2 = PA_setUnistringVariable(&params[1], iCal::listener.updatedRecordsString);
	PA_Unistring u3 = PA_setUnistringVariable(&params[2], iCal::listener.deletedRecordsString);
	PA_Unistring u4 = PA_setUnistringVariable(&params[3], iCal::listener.notificationType);				
	
	PA_ExecuteMethodByID([iCal::listener.listenerMethodId intValue], params, 4);
	
	[iCal::listener unlock];
	
	PA_DisposeUnistring(&u1);
	PA_DisposeUnistring(&u2);
	PA_DisposeUnistring(&u3);
	PA_DisposeUnistring(&u4);	
}

void listenerLoopFinish(){
	
	if(iCal::listener){
		[[NSNotificationCenter defaultCenter]removeObserver:iCal::listener];
		[iCal::listener release];
		iCal::listener = nil;
	}	
	
}

void listenerLoop(){
	
	PA_YieldAbsolute();	
	int listenerProcessNumber = PA_GetCurrentProcessNumber();
	PA_FreezeProcess(listenerProcessNumber);
	
	char done = 0;
	
	while (!done)
	{ 
		PA_YieldAbsolute();
		done = (PA_IsProcessDying()) || ([iCal::listener shouldTerminate]);
		
		if (!done){		
			
			PA_NewProcess((void *)listenerLoopExecuteMethodByID, 512*1024, iCal::listener.notificationType);
			
			PA_FreezeProcess(listenerProcessNumber);
			
		}
	}
	
	listenerLoopFinish();
	
	PA_KillProcess();
}

#pragma mark -

void iCal_Set_notification_method(sLONG_PTR *pResult, PackagePtr pParams)
{
	C_TEXT Param1;
	C_LONGINT returnValue;
	
	Param1.fromParamAtIndex(pParams, 1);
	
	int success = 0;
	
	NSString *methodName = Param1.copyUTF16String();
	
	if(!Param1.getUTF16Length()){
		
		if(iCal::listener)
		{
			[iCal::listener terminate];
			success = 1;
		}
		
	}else{
		
		int methodId = PA_GetMethodID((PA_Unichar *)Param1.getUTF16StringPtr());
		
		if(methodId){
			
			success = 1;
			
			if(!iCal::listener){		
				
				int iCalListenerProcessNumber = PA_NewProcess((void *)listenerLoop, -512*1024, @"$iCal Notification Process");
				
				iCal::listener = [[iCalListener alloc]
							initWithMethodName:methodName
							methodId:[NSNumber numberWithInt:methodId]
							processNumber:[NSNumber numberWithInt:iCalListenerProcessNumber]];
				
				[[NSNotificationCenter defaultCenter]
				 addObserver:iCal::listener 
				 selector:@selector(eventsChanged:)
				 name:CalEventsChangedExternallyNotification 
				 object:[CalCalendarStore defaultCalendarStore]];	
				
				[[NSNotificationCenter defaultCenter]
				 addObserver:iCal::listener 
				 selector:@selector(tasksChanged:)
				 name:CalTasksChangedExternallyNotification 
				 object:[CalCalendarStore defaultCalendarStore]];	
				
				[[NSNotificationCenter defaultCenter]
				 addObserver:iCal::listener 
				 selector:@selector(calendarsChanged:)
				 name:CalCalendarsChangedExternallyNotification 
				 object:[CalCalendarStore defaultCalendarStore]];
				
			}else{
				iCal::listener.listenerMethodName = methodName;				
				iCal::listener.listenerMethodId = [NSNumber numberWithInt:methodId];				
			}
			
		}
		
	}
	
	[methodName release];
	
	returnValue.setIntValue(success);
	returnValue.setReturn(pResult);
}

void iCal_Get_notification_method(sLONG_PTR *pResult, PackagePtr pParams)
{
	C_TEXT Param1;
	C_LONGINT returnValue;
	
	Param1.fromParamAtIndex(pParams, 1);
	
	int success = 0;
	
	if(iCal::listener)
	{
		Param1.setUTF16String(iCal::listener.listenerMethodName);
		Param1.toParamAtIndex(pParams, 1);
		success = 1;		
	}
	
	returnValue.setIntValue(success);	
	returnValue.setReturn(pResult);
}