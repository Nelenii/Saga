#pragma once

#include "Event.h"



namespace Saga
{

	class SAGA_API WindowCloseEvent : public Event
	{
	public:

		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategory::Window)
	};



	class SAGA_API WindowResizeEvent : public Event
	{
	public:

		WindowResizeEvent(unsigned int width, unsigned int height) :
			m_width(width),
			m_height(height)
		{
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategory::Window)		

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "WindowResizeEvent: " << m_width << ", " << m_height;
			return stream.str();
		}

	private:

		unsigned int m_width = 0;
		unsigned int m_height = 0;
	};



	class SAGA_API WindowMovedEvent : public Event
	{
	public:

		WindowMovedEvent(float xOffset, float yOffset) :
			m_xOffset(xOffset),
			m_yOffset(yOffset)
		{
		}

		EVENT_CLASS_TYPE(WindowMoved)
		EVENT_CLASS_CATEGORY(EventCategory::Window)

		inline unsigned int GetXOffset() const { return m_xOffset; }
		inline unsigned int GetYOffset() const { return m_yOffset; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "WindowMovedEvent: " << m_xOffset << ", " << m_yOffset;
			return stream.str();
		}

	private:

		float m_xOffset = 0;
		float m_yOffset = 0;
	};



	class SAGA_API WindowFocusEvent : public Event
	{
	public:

		WindowFocusEvent() {}

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(EventCategory::Window)
	};



	class SAGA_API WindowLostFocusEvent : public Event
	{
	public:

		WindowLostFocusEvent() {}

		EVENT_CLASS_TYPE(WindowLostFocus)
		EVENT_CLASS_CATEGORY(EventCategory::Window)
	};

}
