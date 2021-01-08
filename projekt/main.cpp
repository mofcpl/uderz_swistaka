#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")
#pragma comment(lib,"SDL2_image.lib")
#pragma comment(lib,"SDL2_mixer.lib")
#pragma comment(lib,"SDL2_ttf.lib")

#include<SDL.h>
#include"core.h"

int main(int argc, char **argv)
{

	cCore* Core;
	Core = new cCore;

	Core->Start();
	
	return 0;
}





