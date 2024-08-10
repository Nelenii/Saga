#include "SagaPrecompiledHeaders.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"



namespace Saga
{
	std::shared_ptr<spdlog::logger> Log::ms_engineLogger;
	std::shared_ptr<spdlog::logger> Log::ms_gameLogger;

	void Log::Initialize()
	{
		spdlog::set_pattern("%^[%T] %n %v%$");

		ms_engineLogger = spdlog::stdout_color_mt("ENGINE:");
		ms_engineLogger->set_level(spdlog::level::trace);

		ms_gameLogger = spdlog::stdout_color_mt("GAME:");
		ms_gameLogger->set_level(spdlog::level::trace);
	}

}
