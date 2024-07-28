#include "Saga.h"



class GameTemplate : public Saga::Application
{
public:

	GameTemplate()
	{

	}



	~GameTemplate()
	{

	}
};



Saga::Application* Saga::CreateApplication()
{
	return new GameTemplate();
}
