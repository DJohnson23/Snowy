#pragma once

#include "Core.h"

#include "Window.h"
#include "Snowy/LayerStack.h"
#include "Snowy/Events/Event.h"
#include "Snowy/Events/ApplicationEvent.h"

#include "Snowy/ImGui/ImGuiLayer.h"

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

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

	private:
		static Application* s_Instance;
	};

	// To ve defined in CLIENT
	Application* CreateApplication();

}

