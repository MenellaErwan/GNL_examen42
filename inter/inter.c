#include <unistd.h>

int main(int argc, char **arg)
{
	char array[256];
	int i;

	i = -1;
	while (++i < 256)
		array[i] = 0;
	if (argc == 3)
	{
		i = -1;
		while (arg[2][++i])
			array[(int)arg[2][i]] = 1;
		i = -1;
		while (arg[1][++i])
			if (array[(int)arg[1][i]]--)
				write(1, &arg[1][i], 1);
	}
	write(1, "\n", 1);
	return (0);
}