#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace Snowy {

	class SNOWY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To ve defined in CLIENT
	Application* CreateApplication();

}

