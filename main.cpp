#include "GameManager.h"
#include <memory>


int main(int argc, char *argv[])
{   
    wd::GameManager* game = wd::GameManager::GetInstance();

	game->Run();

	game->Release();
    game = nullptr;
	

	return 0;
    return 0;
}
