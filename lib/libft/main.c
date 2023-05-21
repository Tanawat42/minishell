#include "libft.h"
#include <stdio.h>

int main () {
	// char **split = ft_split("echo \"> This is a string\" >", '>');
	char **split = ft_split_notqoute("echo \">> This is a string\" >> test", ">>");

	if (split)
	{
		for (int i = 0; split[i]; i++)
		{
			ft_putendl_fd(split[i], 1);
			free(split[i]);
		}
		free(split);
	}
}
