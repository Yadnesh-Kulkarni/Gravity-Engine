#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Gravity {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^ [%T] %n : %v : %g%$");
		s_CoreLogger = spdlog::stderr_color_mt("Gravity");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stderr_color_mt("Application");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}



