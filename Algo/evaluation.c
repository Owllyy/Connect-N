#include "algo.h"

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
            if (board[i][j] && board[i][j] != player)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i++;
            j--;
        }
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
            if (board[i][j] && board[i][j] != player)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i--;
            j--;
        }
    }
    return (count);
}

int find_diag(int player, char **board, int x, int y)
{
    int score = 0;

    score += pow(10, diag_up_r(player, board, x, y));
    score += pow(10, diag_up_l(player, board, x, y));
    score += pow(10, diag_down_r(player, board, x, y));
    score += pow(10, diag_down_l(player, board, x, y));

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
            if (board[i][j] && board[i][j] != player)
            {
                count = 0;
                break ;
            }
            if (board[i][j] == player)
                count++;
            i--;
        }
    }
    return (count);
}

int find_line(int player, char **board, int x, int y)
{
    int score = 0;

    score += pow(10, line_up(player, board, x, y));
    score += pow(10, line_left(player, board, x, y));
    score += pow(10, line_right(player, board, x, y));

    return (score);
}

int score_pawn(int player, char **board, int x, int y)
{
    return (find_diag(player, board, x, y) + find_line(player, board, x, y));
}

int evaluate_board(node *arg)
{
    int i = 0;
    int j;
    int eval = 0;

    while (i < width)
    {
        j = 0;
        while (j < height)
        {
            printf("j = %d, i = %d\n", j, i);
            if (arg->board[i][j] == 0)
                j++;
            if (arg->board[i][j] == 1)
                eval += score_pawn(1, arg->board, i, j);
            if (arg->board[i][j] == 2)
                eval -= score_pawn(2, arg->board, i, j);
            j++;
        }
        i++;
    }
    return (eval);
}