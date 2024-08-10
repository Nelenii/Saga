#include "SagaPrecompiledHeaders.h"
#include "Application.h"

#include "Events/WindowEvent.h"
#include "Events/KeyEvent.h"
#include "Log.h"



namespace Saga
{

	Application::Application()
	{
	}



	Application::~Application()
	{
	}



	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);

		if (e.IsInCategory(EventCategory::Window))
		{
			LOGTRACE_SAGA(e.ToString());
		}
		if (e.IsInCategory(EventCategory::Input))
		{
			LOGTRACE_SAGA(e.ToString());
		}

		KeyReleasedEvent k(123);
		if (k.IsInCategory(EventCategory::Keyboard) && k.IsInCategory(EventCategory::Input))
		{
			LOGTRACE_GAME(k.ToString());
		}
		LOGTRACE_GAME("flags values = {0}", k.GetCategoryFlags());
		
		while (true)
		{
		}
	}

}
