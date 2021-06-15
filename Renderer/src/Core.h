#pragma once
#include "log.h"


#ifndef vulkan_windows
#define vulkan_windows
#endif

//log 

#define SE_LOG_TRACE(...)		Spaceng::log::GetLogger()->trace(__VA_ARGS__); //not functional
#define SE_LOG_INFO(...)		Spaceng::log::GetLogger()->info(__VA_ARGS__);
#define SE_LOG_WARN(...)		Spaceng::log::GetLogger()->warn(__VA_ARGS__);
#define SE_LOG_ERROR(...)		Spaceng::log::GetLogger()->error(__VA_ARGS__);
#define SE_LOG_CRITICAL(...)	Spaceng::log::GetLogger()->critical(__VA_ARGS__);

#ifdef SE_DEBUG
#define SE_LOG_DEBUG(...)		Spaceng::log::GetLogger()->debug(__VA_ARGS__);
#else
#define SE_LOG_DEBUG(...)
#endif


#ifdef SE_DEBUG
#define SE_ENABLE_ASSERT
#endif
#ifdef SE_ENABLE_ASSERT
#define SE_ASSERT(condition, ...) { if(!(condition)) { SE_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SE_ASSERT(...)
#endif
