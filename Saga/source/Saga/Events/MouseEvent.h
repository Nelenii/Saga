#pragma once

#include "Event.h"



namespace Saga
{

	class SAGA_API MouseMovedEvent : public Event
	{
	public:

		MouseMovedEvent(float x, float y) :
			m_x(x),
			m_y(y)
		{
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse)

		inline float GetX() const { return m_x; }
		inline float GetY() const { return m_y; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseMovedEvent: " << m_x << ", " << m_y;
			return stream.str();
		}

	private:

		float m_x = 0.f;
		float m_y = 0.f;
	};



	class SAGA_API MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(float xOffset, float yOffset) :
			m_xOffset(xOffset),
			m_yOffset(yOffset)
		{
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse)

		inline float GetXOffset() const { return m_xOffset; }
		inline float GetYOffset() const { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
			return stream.str();
		}

	private:

		float m_xOffset = 0.f;
		float m_yOffset = 0.f;
	};



	class SAGA_API MouseButtonEvent : public Event
	{
	public:

		EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Mouse | EventCategory::MouseButton)

		inline int GetButton() const { return m_button; }

	protected:

		MouseButtonEvent(int button) :
			m_button(button)
		{
		}

	protected:

		int m_button = -1;
	};



	class SAGA_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonPressedEvent(int button) :
			MouseButtonEvent(button)
		{
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonPressedEvent: " << m_button;
			return stream.str();
		}
	};



	class SAGA_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonReleasedEvent(int button) :
			MouseButtonEvent(button)
		{
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "MouseButtonReleasedEvent: " << m_button;
			return stream.str();
		}
	};

}
