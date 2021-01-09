#pragma once

#ifdef SN_PLATFORM_WINDOWS

extern Snowy::Application* Snowy::CreateApplication();

int main(int argc, char** argv) {
	Snowy::Log::Init();

	SN_CORE_WARN("Initialized Logger!");
	SN_INFO("Hello!");

	int a = 5;
	SN_INFO("Hello! Var={0}", a);

	auto app = Snowy::CreateApplication();
	app->Run();
	delete app;
}

#endif