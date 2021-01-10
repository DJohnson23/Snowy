#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Snowy/Events/ApplicationEvent.h"

#include "Window.h"

namespace Snowy {

	class SNOWY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To ve defined in CLIENT
	Application* CreateApplication();

}

