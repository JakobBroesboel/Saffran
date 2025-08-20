#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Saffran {

	class SAFFRAN_API Log
	{

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	
	private:
		const static std::string log_pattern;

		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

		static std::shared_ptr<spdlog::logger> InitLogger(const std::string& logger_name, spdlog::level::level_enum log_level);
	};

}


// Core log macros
#define SF_CORE_TRACE(...) ::Saffran::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SF_CORE_INFO(...)  ::Saffran::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SF_CORE_WARN(...)  ::Saffran::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SF_CORE_ERROR(...) ::Saffran::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SF_CORE_FATAL(...) ::Saffran::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define SF_TRACE(...)      ::Saffran::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SF_INFO(...)       ::Saffran::Log::GetClientLogger()->info(__VA_ARGS__)
#define SF_WARN(...)       ::Saffran::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SF_ERROR(...)      ::Saffran::Log::GetClientLogger()->error(__VA_ARGS__)
#define SF_FATAL(...)      ::Saffran::Log::GetClientLogger()->fatal(__VA_ARGS__)