#pragma once

#include "Event.h"

#include <sstream>



namespace Saga
{

	class SAGA_API KeyEvent : public Event
	{
	public:

		inline int GetKeyCode() const { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategory::Input | EventCategory::Keyboard)

	protected:

		KeyEvent(int keycode)
			: m_keyCode(keycode)
		{
		}

	protected:

		int m_keyCode = -1;
	};



	class SAGA_API KeyPressedEvent : public KeyEvent
	{
	public:

		KeyPressedEvent(int keyCode, int repeatCount) :
			KeyEvent(keyCode),
			m_repeatCount(repeatCount)
		{
		}
		EVENT_CLASS_TYPE(KeyPressed)

		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return stream.str();
		}

	protected:

		int m_repeatCount = 0;
	};



	class SAGA_API KeyReleasedEvent : public KeyEvent
	{
	public:

		KeyReleasedEvent(int keyCode) :
			KeyEvent(keyCode)
		{
		}

		EVENT_CLASS_TYPE(KeyReleased)

		std::string ToString() const override
		{
			std::stringstream stream;
			stream << "KeyReleasedEvent: " << m_keyCode;
			return stream.str();
		}
	};

}
