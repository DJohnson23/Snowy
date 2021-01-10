#include <Snowy.h>

class ExampleLayer : public Snowy::Layer
{
public:
	ExampleLayer() : Layer("Example") {}

	void OnUpdate() override {
		SN_INFO("ExampleLayer::Update");
	}

	void OnEvent(Snowy::Event& event) override {
		SN_TRACE("{0}", event);
	}
};

class Sandbox : public Snowy::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new Snowy::ImGuiLayer());
	}

	~Sandbox() {

	}
};

Snowy::Application* Snowy::CreateApplication() {
	return new Sandbox();
}