#pragma once

#include "Core.h"
#include "Events/Event.h"



namespace Saga
{

	class SAGA_API Application
	{
	public:

		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
