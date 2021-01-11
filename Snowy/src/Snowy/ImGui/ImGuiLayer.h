#pragma once

#include "Snowy/Layer.h"

#include "Snowy/Events/ApplicationEvent.h"
#include "Snowy/Events/KeyEvent.h"
#include "Snowy/Events/MouseEvent.h"

namespace Snowy {

	class SNOWY_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};

}