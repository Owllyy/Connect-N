#include "algo.h"

int ft_pow(int value, int pow)
{
    int i = 0;
    int test = value;
    int ret = value;
    while (i < pow)
    {
        ret *= test;
        i++;
    }
    return (ret);
}

int diag_up_r(int player, char **board, int x, int y)
{
    int i = x;
    int j = y;
    int count = 0;

    if (i + (move_to_win - 1) < width && j + (move_to_win - 1) < height)
    {
        while (i < width && j < height && count < move_to_win)
        {
            if (board[i][j] && board[i][j] != player)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i++;
            j++;
        }
        if (count == move_to_win)
            return (-1);
    }
    return (count);
}

int diag_up_l(int player, char **board, int x, int y)
{
    int i = x;
    int j = y;
    int count = 0;

    if (i - (move_to_win - 1) >= 0 && j + (move_to_win - 1) < height)
    {
        while (i >= 0 && j < height && count < move_to_win)
        {
            if (board[i][j] && board[i][j] != player)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i--;
            j++;
        }
        if (count == move_to_win)
            return (-1);
    }
    return (count);
}

int diag_down_r(int player, char **board, int x, int y)
{
    int i = x;
    int j = y;
    int count = 0;

    if (i + (move_to_win - 1) < width && j - (move_to_win - 1) >= 0)
    {
        while (i < width && j >= 0 && count < move_to_win)
        {
            if (board[i][j] && board[i][j] != player && board[i][j] != 0)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i++;
            j--;
        }
        if (count == move_to_win)
            return (-1);
    }
    return (count);
}

int diag_down_l(int player, char **board, int x, int y)
{
    int i = x;
    int j = y;
    int count = 0;

    if (i - (move_to_win - 1) >= 0 && j + (move_to_win - 1) >= 0)
    {
        while (i >= 0 && j >= 0 && count < move_to_win)
        {
            if (board[i][j] && board[i][j] != player && board[i][j] != 0)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i--;
            j--;
        }
        if (count == move_to_win)
            return (-1);
    }
    return (count);
}

int find_diag(int player, char **board, int x, int y)
{
    int score = 0;
    int ret = 0;

    ret = diag_up_r(player, board, x, y);
    if (ret == -1)
        return (-1);
    score += ft_pow(10, ret);
    ret = diag_up_l(player, board, x, y);
    if (ret == -1)
        return (-1);
    score += ft_pow(10, ret);
    ret = diag_down_r(player, board, x, y);
    if (ret == -1)
        return (-1);
    score += ft_pow(10, ret);
    ret = diag_down_l(player, board, x, y);
    if (ret == -1)
        return (-1);
    score += ft_pow(10, ret);

    return (score);
}

int line_up(int player, char **board, int x, int y)
{
    int i = x;
    int j = y;
    int count = 0;

    if (j + (move_to_win - 1) < height)
    {
        while (j < height && count < move_to_win)
        {
            if (board[i][j] && board[i][j] != player)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            j++;
        }
        if (count == move_to_win)
            return (-1);
    }
    return (count);
}

int line_right(int player, char **board, int x, int y)
{
    int i = x;
    int j = y;
    int count = 0;

    if (i + (move_to_win - 1) < width)
    {
        while (i < width && count < move_to_win)
        {
            if (board[i][j] && board[i][j] != player)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i++;
        }
        if (count == move_to_win)
            return (-1);
    }
    return (count);
}

int line_left(int player, char **board, int x, int y)
{
    int i = x;
    int j = y;
    int count = 0;

    if (i - (move_to_win - 1) >= 0)
    {
        while (i >= 0 && count < move_to_win)
        {
            if (board[i][j] && board[i][j] != player && board[i][j] != 0)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i--;
        }
        if (count == move_to_win)
            return (-1);
    }
    return (count);
}

int find_line(int player, char **board, int x, int y)
{
    int score = 0;
    int ret = 0;

    ret = line_up(player, board, x, y);
    if (ret == -1)
        return (-1);
    score += ft_pow(10, ret);
    ret = line_right(player, board, x, y);
    if (ret == -1)
        return (-1);
    score += ft_pow(10, ret);
    ret = line_left(player, board, x, y);
    if (ret == -1)
        return (-1);
    score += ft_pow(10, ret);

    return (score);
}

int score_pawn(int player, char **board, int x, int y)
{
    int score = 0;
    int ret = 0;
    ret = find_line(player, board, x, y);
    if (ret == -1 && player)
        return (-1);
    score += ret;
    ret = find_diag(player, board, x, y);
    if (ret == -1 && player)
        return (-1);
    score += ret;
    return (score);
}

int evaluate_board(node *arg)
{
    int i = 0;
    int j;
    int eval = 0;
    int ret = 0;

    while (i < width)
    {
        j = 0;
        while (j < height && ret != -1)
        {
            if (arg->board[i][j] == 0)
                j++;
            if (arg->board[i][j] == 1)
            {
                ret = score_pawn(1, arg->board, i, j);
                eval += ret;
            }
            if (arg->board[i][j] == 2)
            {
                ret = score_pawn(2, arg->board, i, j);
                eval -= ret;
            }
            j++;
        }
        if (ret == -1 && arg->player)
            return (INT_MIN);
        if (ret == -1)
            return (INT_MAX);
        i++;
    }
    return (eval);
}