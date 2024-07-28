#pragma once



#ifdef SAGA_PLATFORM_WINDOWS

extern Saga::Application* Saga::CreateApplication();

int main(int argc, char** argv)
{
	auto application = Saga::CreateApplication();
	application->Run();
	delete application;
}

#endif
