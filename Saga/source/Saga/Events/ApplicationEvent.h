#pragma once

#include "Event.h"



namespace Saga
{

	class SAGA_API AppTickEvent : public Event
	{
	public:

		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategory::Application)
	};



	class SAGA_API AppUpdateEvent : public Event
	{
	public:

		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategory::Application)
	};



	class SAGA_API AppRenderEvent : public Event
	{
	public:

		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategory::Application)
	};

}
