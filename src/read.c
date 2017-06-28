#include "fdf.h"

grid		**ft_read(char *file, int *row_countp, int *col_countp)
{	
	int		fd;
	char	buff[1];
	char	*row;
	char	**split;
	int		row_count;
	int		col_count;
	grid	**cell;

	row_count = 0;
	col_count = 0;
	fd = open(file, O_RDONLY);
	while (read(fd, buff, 1))
		if (buff[0] == '\n')
			row_count++;
	fd = open(file, O_RDONLY);
	cell = (grid **)malloc(sizeof(grid *) * (row_count + 1));
	row_count = 0;
	col_count = 0;
	while (get_next_line(fd, &row))
	{
		split = ft_strsplit((const char*)row, ' ');
		col_count = 0;
		while (split[col_count] != NULL)
			col_count++;
		cell[row_count] = (grid *)malloc(sizeof(grid) * (col_count + 1));
		col_count = 0;
		while(split[col_count] != NULL)
		{
			cell[row_count][col_count].height = ft_atoi((const char*)split[col_count]);
			col_count++;
		}
		row_count++;
	}
	*row_countp = row_count;
	*col_countp = col_count;
	for (int i = 0; split[i] != NULL; i++)
		free(split[i]);
	free (split);
	return (cell);
}