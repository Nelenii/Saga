#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"



namespace Saga
{

	class SAGA_API Log
	{
	public:

		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger()	{ return ms_engineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetGameLogger()		{ return ms_gameLogger; }

	private:

		static std::shared_ptr<spdlog::logger> ms_engineLogger;
		static std::shared_ptr<spdlog::logger> ms_gameLogger;
	};

}



#define LOGTRACE_SAGA(...)		Saga::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LOGINFO_SAGA(...)		Saga::Log::GetEngineLogger()->info(__VA_ARGS__)
#define LOGWARNING_SAGA(...)	Saga::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LOGERROR_SAGA(...)		Saga::Log::GetEngineLogger()->error(__VA_ARGS__)
#define LOGFATAL_SAGA(...)		Saga::Log::GetEngineLogger()->fatal(__VA_ARGS__)

#define LOGTRACE_GAME(...)		Saga::Log::GetGameLogger()->trace(__VA_ARGS__)
#define LOGINFO_GAME(...)		Saga::Log::GetGameLogger()->info(__VA_ARGS__)
#define LOGWARNING_GAME(...)	Saga::Log::GetGameLogger()->warn(__VA_ARGS__)
#define LOGERROR_GAME(...)		Saga::Log::GetGameLogger()->error(__VA_ARGS__)
#define LOGFATAL_GAME(...)		Saga::Log::GetGameLogger()->fatal(__VA_ARGS__)
