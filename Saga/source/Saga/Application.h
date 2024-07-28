#pragma once

#include "Core.h"



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
