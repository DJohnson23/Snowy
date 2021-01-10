#include "Application.h"

#include "Snowy/Events/ApplicationEvent.h"
#include "Snowy/Log.h"

namespace Snowy {

	Application::Application() {

	}

	Application::~Application() {

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		SN_TRACE(e);

		while (true);
	}

}