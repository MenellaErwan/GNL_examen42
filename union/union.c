#include <unistd.h>

int main(int argc, char **arg)
{
	int j = 0;
	int i = -1;
	char str[256];

	while (++i < 256)
		str[i] = 1;
	if (argc == 3)
	{
		while(++j < 3 && (i = -1))
			while(arg[j][++i])
				if (str[(int)arg[j][i]]-- == 1)
					write(1, &arg[j][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}