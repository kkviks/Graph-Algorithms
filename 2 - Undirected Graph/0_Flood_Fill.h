//           W  N  E  S
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

int R, C; //Size

void floodFill(char mat[][1000], int i, int j, char ch, char color)
{
    if (i < 0 or j < 0 or i >= R or j >= C)
    {
        return;
    }

    if (mat[i][j] != ch)
    {
        return;
    }

    mat[i][j] = color;

    for (int k = 0; k < 4; k++)
    {
        floodFill(mat, i + dx[k], j + dy[k], ch, color);
    }
}