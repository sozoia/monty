#include "monty.h"

stack_t *linked;

int main(int argc, char *argv[])
{
	const char *file_name;
	FILE *file;
	char *buf = NULL;
	char **tokens;
	size_t len = 5;
	int exit_stat = 1;

	if (argc == 2)
	{
		file_name = argv[1];
		file = fopen(file_name, "r");

		if (!file)
		{
			len = strlen("opening error");
			write(STDERR_FILENO, "opening error", len);
			return (1);
		}
		else
		{
			while (getline(&buf, &len, file) != -1)
			{
				tokens = parse(buf);
				if (tokens && buf)
				{
					exit_stat = excute(tokens);
					free(tokens);
				}
			}
		}
		free_linked();
		free(buf);
		fclose(file);
	}
	exit (exit_stat);
}
