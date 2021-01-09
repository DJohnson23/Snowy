#include <Snowy.h>

class Sandbox : public Snowy::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

Snowy::Application* Snowy::CreateApplication() {
	return new Sandbox();
}