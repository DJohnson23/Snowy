#pragma once

#ifdef SN_PLATFORM_WINDOWS

extern Snowy::Application* Snowy::CreateApplication();

int main(int argc, char** argv) {
	auto app = Snowy::CreateApplication();
	app->Run();
	delete app;
}

#endif