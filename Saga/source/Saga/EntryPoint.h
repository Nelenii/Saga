#pragma once



#ifdef SAGA_PLATFORM_WINDOWS

extern Saga::Application* Saga::CreateApplication();

int main(int argc, char** argv)
{
	Saga::Log::Initialize();
	LOGWARNING_SAGA("Initialized log!");
	int a = 5;
	LOGINFO_GAME("Initialized log {0}!", a);

	auto application = Saga::CreateApplication();
	application->Run();
	delete application;
}

#endif
