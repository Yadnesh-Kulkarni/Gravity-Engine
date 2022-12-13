#pragma once
#include <memory>
#include "Core.h"
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Gravity {
	class GVT_API Log
	{
		// Two Loggers, 1 for Engine and 1 for Sandbox 
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		 static std::shared_ptr<spdlog::logger> s_CoreLogger;
		 static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Macros For Core
#define GVT_CORE_INFO(...)  Gravity::Log::GetCoreLogger()->info(__VA_ARGS__); 
#define GVT_CORE_TRACE(...) Gravity::Log::GetCoreLogger()->trace(__VA_ARGS__); 
#define GVT_CORE_WARN(...)  Gravity::Log::GetCoreLogger()->warn(__VA_ARGS__); 
#define GVT_CORE_ERROR(...) Gravity::Log::GetCoreLogger()->error(__VA_ARGS__); 

// Macros for Sandbox
#define GVT_INFO(...)       Gravity::Log::GetClientLogger()->info(__VA_ARGS__);
#define GVT_TRACE(...)      Gravity::Log::GetClientLogger()->trace(__VA_ARGS__);
#define GVT_WARN(...)       Gravity::Log::GetClientLogger()->warn(__VA_ARGS__);
#define GVT_ERROR(...)      Gravity::Log::GetClientLogger()->error(__VA_ARGS__);