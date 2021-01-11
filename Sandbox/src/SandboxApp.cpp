#include <Snowy.h>

#include "imgui/imgui.h"

class ExampleLayer : public Snowy::Layer
{
public:
	ExampleLayer() : Layer("Example") {
	}

	void OnUpdate() override {
		if (Snowy::Input::IsKeyPressed(SN_KEY_TAB)) {
			SN_TRACE("Tab key is pressed");
		}
	}

	void OnImGuiRender() override {
		//ImGui::Begin("Test");
		//ImGui::Text("Hello World");
		//ImGui::End();
	}

	void OnEvent(Snowy::Event& event) override {
		if (event.GetEventType() == Snowy::EventType::KeyPressed) {
			Snowy::KeyPressedEvent& e = (Snowy::KeyPressedEvent&) event;
			SN_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox : public Snowy::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

Snowy::Application* Snowy::CreateApplication() {
	return new Sandbox();
}