#include "algo.h"

int    build_tree(node *old, int depth, int alpha, int beta, int max_player)
{
    int value;
    int save;
    
    if (!depth)
    {
        old->score = evaluate_board(old);
        return (old->score);
    }
    node **new = new_child(old);
	old->next = new;
    if (max_player)
    {
        value = INT_MIN;
        for (int i = 0; i < width; i++)
        {
            if ((save = build_tree(new[i], depth - 1, alpha, beta, 0)) > value)
                value = save;
            if (value > beta)
                break ;
            if (alpha < value)
                alpha = value;
        }
        if (old->score < value)
            old->score = value;
        return (value);
    }
    else
    {
        value = INT_MAX;
        for (int i = 0; i < width; i++)
        {
            if ((save = build_tree(new[i], depth - 1, alpha, beta, 1)) < value)
                value = save;
            if (value < alpha)
                break ;
            if (beta > value)
                beta = value;
        }
        if (old->score < value)
            old->score = value;
        return (value);
    }
}