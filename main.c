#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

int main (int argc, char argv[])
{
	do
	{
		p1();

		cmd = _read();

		if(!cmd)
		{
			exit(EXIT_SUCCESS);
		}

		if(cmd[0] == '\0' || _strcmp(cmd,"\n") == 0)
		{
			free(cmd);
			continue;
		}

		if(strcmp(cmd, "exit\n") == 0)
		{
			free(cmd);
			break;
		}
		printf("%s\n",cmd);

	}while(1);
	free(cmd);

	exit(EXIT_SUCCESS);
}

