#pragma once

#include "Core.h"

#include "Window.h"
#include "Snowy/LayerStack.h"
#include "Snowy/Events/Event.h"
#include "Snowy/Events/ApplicationEvent.h"


namespace Snowy {

	class SNOWY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To ve defined in CLIENT
	Application* CreateApplication();

}

