#ifndef SORTERS
# define SORTERS

#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    if (!(*a ^ *b))
        return ;
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void    print_n_array(int *array, int n)
{
    int i;

    i = -1;
    while (++i < n)
        printf("%d ", array[i]);
    printf("\n");
}

void    sort_selection_sort(int *array, int size)
{
    int i;
    int j;
    int loc_min;

    i = -1;
    while (++i < size)
    {
        j = i - 1;
        loc_min = i;
        while (++j < size)
            if (array[j] < array[loc_min])
                loc_min = j;
        ft_swap(&array[i], &array[loc_min]);
    }
}

// void    sort_bubble_sort(int *array, int size)
// {
//     return ;
// }

void	quicksort(int *arr, int size)
{
	int	i;
	int	pivot_loc;
	int	end;

	if (size <= 1)
		return ;
	i = 0;
	end = size - 1;
	while (i <= end)
	{
		while (arr[i] < arr[size])
			i++;
		while (arr[end] > arr[size])
			end--;
		if (arr[i] > arr[size])
			ft_swap(&arr[i--], &arr[end--]);
		i++;
	}
	ft_swap(&arr[end + 1], &arr[size]);
	pivot_loc = end;
	quicksort(arr, pivot_loc);
	quicksort(arr + pivot_loc, size - pivot_loc);
}


/*
** Merge sort would work a lot better with linked list. Here the shifting
** makes it preform less than optimal, but it does it in place...
*/
void    sort_merge_sort(int *array, int size)
{
    int temp;
    int i;
    int j;
    int shift;
    int cut;

    if (size <= 1)
        return ;
    else if (size >= 2 && (i = -1))
    {
        j = 0;
        cut = size / 2;
        sort_merge_sort(array, cut);
        sort_merge_sort(array + cut, size - cut);
        while (++i < size - 1 && j < size - cut)
            if (!(array[i] < array[j + cut]) && (shift = -1))
            {
                temp = array[j++ + cut];
                while (++shift < cut - i + j)
                    array[cut + j - shift - 1] = array[cut + j - shift - 2];
                array[i] = temp;
            }
    }
}

#endif
