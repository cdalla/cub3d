
#include "cube.h"

// int main(void)
// {
// 	ft_strlen("ciao");
	
// 	ft_strncmp("hello", "hi", 2);	
	
	
// 	return (0);
// }


/*
check for number of args
check file format
open file
parse the file
*/
int	main(int argc, char	**argv)
{
	t_data	game;
	
	//initialize game content to check nothing is empty after parser
	
	if (argc != 2 || ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4))
		return (1);//error message invalid input
	if (parser(argv[1], &game))
		return (1);//error message invalid file content
	
	//start game
	
	return (0);
}