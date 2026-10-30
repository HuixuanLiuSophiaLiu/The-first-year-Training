//这些是剪了枝的递归回溯
#include <stdio.h>

int m, n;
int OriginalGrid[10][10];
int TreeLocation[100][2];
int BlankNum;
int PreviousMax;
int RowBound[101];

void PlantTheTree(int TreeNum, int CurrentPos, int m, int n, int TreeMap[][10])
{
    if (TreeNum + RowBound[CurrentPos] <= PreviousMax)
        return;

    if (CurrentPos == BlankNum + 1)
    {
        if (TreeNum > PreviousMax) PreviousMax = TreeNum;
        return;
    }

    int x = TreeLocation[CurrentPos][0];
    int y = TreeLocation[CurrentPos][1];

    if (!TreeMap[x][y - 1] && !TreeMap[x][y + 1] &&
        !TreeMap[x - 1][y - 1] && !TreeMap[x - 1][y + 1])
    {
        TreeMap[x][y] = 1;
        PlantTheTree(TreeNum + 1, CurrentPos + 1, m, n, TreeMap);
        TreeMap[x][y] = 0;
    }

    PlantTheTree(TreeNum, CurrentPos + 1, m, n, TreeMap);
}

int main(void)
{
    char c;

    scanf("%d %d", &m, &n);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf(" %c", &c);
            if (c == '.')
            {
                OriginalGrid[i][j] = 0;
                TreeLocation[++BlankNum][0] = i;
                TreeLocation[BlankNum][1] = j;
            }
            if (c == '#') OriginalGrid[i][j] = 1;
        }
    }

    for (int k = 1; k <= BlankNum + 1; k++)
    {
        int total = 0;
        int j = k;
        while (j <= BlankNum)
        {
            int r = TreeLocation[j][0];

            int j2 = j;
            while (j2 + 1 <= BlankNum && TreeLocation[j2 + 1][0] == r)
                j2++;

            int mask = 0;
            for (int t = j; t <= j2; t++)
                mask |= 1 << (TreeLocation[t][1] - 1);

            int bestRow = 0;
            int maxMask = 1 << n;
            for (int s = 0; s < maxMask; s++)
            {
                if (s & ~mask) continue;
                if (s & (s << 1)) continue;
                int cnt = 0, t2 = s;
                while (t2) { cnt += t2 & 1; t2 >>= 1; }
                if (cnt > bestRow) bestRow = cnt;
            }

            total += bestRow;
            j = j2 + 1;
        }
        RowBound[k] = total;
    }

    int EmptyMap[10][10] = {0};
    PlantTheTree(0, 1, m, n, EmptyMap);

    printf("%d\n", PreviousMax);

    return 0;
}

/*这些是没剪枝的递归回溯
#include <stdio.h>
int m,n;

int TreeLocation[100][2];
int BlankNum;
int PreviousMax;

void PlantTheTree(int TreeNum,int CurrentPos,int TreeMap[][10])
{
    if(CurrentPos==BlankNum+1)
    {
        if(TreeNum>PreviousMax) PreviousMax=TreeNum;
        return;
    } 
    if(BlankNum-CurrentPos+1+TreeNum<=PreviousMax) return;
    int x=TreeLocation[CurrentPos][0];
    int y=TreeLocation[CurrentPos][1];

    if(!TreeMap[x][y-1]&&!TreeMap[x][y+1]&&!TreeMap[x-1][y-1]&&!TreeMap[x-1][y+1])
    {
        TreeMap[x][y]=1;
        PlantTheTree(TreeNum+1,CurrentPos+1,TreeMap);
        TreeMap[x][y]=0;
    }
    PlantTheTree(TreeNum,CurrentPos+1,TreeMap);
}

int main(void)
{
    char c;
    int TreeMap[10][10]={0};

    scanf("%d %d",&m,&n);

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf(" %c",&c);
            if(c=='.') 
            {
                //OriginalGrid[i][j]=0;
                TreeLocation[++BlankNum][0]=i;
                TreeLocation[BlankNum][1]=j;
            }
            //if(c=='#') OriginalGrid[i][j]=1;
        }
    }

    PlantTheTree(0,1,TreeMap);

    printf("%d",PreviousMax);

    return 0;
}
    */