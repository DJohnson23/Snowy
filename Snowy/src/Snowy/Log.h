#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Snowy {
	class SNOWY_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define SN_CORE_TRACE(...)     ::Snowy::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SN_CORE_INFO(...)      ::Snowy::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SN_CORE_WARN(...)      ::Snowy::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SN_CORE_ERROR(...)     ::Snowy::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SN_CORE_FATAL(...)     ::Snowy::Log::GetCoreLogger()->fatal(__VA_ARGS__)
						       
// Core log macros		       
#define SN_TRACE(...)          ::Snowy::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SN_INFO(...)           ::Snowy::Log::GetClientLogger()->info(__VA_ARGS__)
#define SN_WARN(...)           ::Snowy::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SN_ERROR(...)          ::Snowy::Log::GetClientLogger()->error(__VA_ARGS__)
#define SN_FATAL(...)          ::Snowy::Log::GetClientLogger()->fatal(__VA_ARGS__)