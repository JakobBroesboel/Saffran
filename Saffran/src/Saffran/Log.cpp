#include "Log.h"


namespace Saffran {

	const std::string Log::log_pattern = "%^[%T] %n: %v%$";

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern(log_pattern);

		s_CoreLogger = InitLogger("SAFFRAN", spdlog::level::trace);
		s_ClientLogger = InitLogger("APP", spdlog::level::trace);
	}

	std::shared_ptr<spdlog::logger> Log::InitLogger(const std::string& logger_name, spdlog::level::level_enum log_level) {
		std::shared_ptr<spdlog::logger> logger = spdlog::stdout_color_mt(logger_name);
		logger->set_level(log_level);

		return logger;
	}

}