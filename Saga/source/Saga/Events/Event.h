#pragma once

#include "Saga/Core.h"

#include <string>
#include <functional>



namespace Saga
{

	enum class EventType
	{
		None = 0,

		WindowClose,
		WindowResize,
		WindowFocus,
		WindowLostFocus,
		WindowMoved,

		AppTick,
		AppUpdate,
		AppRender,

		KeyPressed,
		KeyReleased,

		MouseButtonPressed,
		MouseButtonReleased,
		MouseMoved,
		MouseScrolled
	};



	enum class EventCategory : uint8
	{
		None			= 0,
		Window			= 1 << 0,
		Application		= 1 << 1,
		Input			= 1 << 2,
		Keyboard		= 1 << 3,
		Mouse			= 1 << 4,
		MouseButton		= 1 << 5
	};
	GENERATE_ENUM_CLASS_FLAGS_OPERATORS(EventCategory)




#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; } \
								virtual EventType GetType() const override { return GetStaticType(); } \
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)	virtual uint8 GetCategoryFlags() const override { return (uint8)(category); }



	class SAGA_API Event
	{
		friend class EventDispatcher;

	public:

		virtual EventType GetType() const = 0;
		virtual const char* GetName() const = 0;
		virtual uint8 GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName();  }

		inline bool IsInCategory(EventCategory category) const { return GetCategoryFlags() & (uint8)category; }

	protected:

		bool m_handled = false;
	};



	class SAGA_API EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:

		EventDispatcher(Event& event)
			: m_event(event)
		{
		}

		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_event.GetType() == T::GetStaticType())
			{
				m_event.m_handled = func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:

		Event& m_event;
	};



	inline std::ostream& operator << (std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}

}
