
#include "push_swap.h"


void    ss(t_push_swap *arrays)
{
    int tmp;
    
    if (arrays->size_a <= 1 || arrays->size_b <=1)
        return ;
    tmp = arrays->a[0];
    arrays->a[0] = arrays->a[1];
    arrays->a[1] = tmp;
    tmp = arrays->b[0];
    arrays->b[0] = arrays->b[1];
    arrays->b[1] = tmp;
    write(1, "ss\n", 3);
}
