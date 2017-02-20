#include "ConsoleUpdator.h"

int 
main(int argc, char* argv)
{
	CONSOLE_CURSOR_INFO cursor;
	HCURSOR c;
	
	for(int i = 0; i <= 1000; ++i)
	{
		std::cout << "hello world! " << i << std::endl;

		// line limit 5
		if(GetCursor(CURSOR_POSITION::y) >= 5)
		{
			SetCursor(0, 0);
			std::fflush(stdout);
		}
		Sleep(100);
	}

	return NULL;
}
