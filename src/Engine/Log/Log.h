#pragma once
#include "Core/SubSystem.h"
#include <chrono>
//====================

namespace TmingEngine
{
	static class ENGINE_CLASS Debug : public Subsystem
	{
	public:
	 static void Log(const char * message,...);

	private:
	};
}