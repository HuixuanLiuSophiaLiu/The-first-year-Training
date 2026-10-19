#include<stdio.h>
char c;
int eleven_w,eleven_l,twenty_w,twenty_l;
int twen_num;
int record[2600][2];
int main()
{
    c=getchar();
    while(c!='E')
    {
        if(c=='W')
        {
            eleven_w++;
            twenty_w++;
        }
        else if(c=='L')
        {
            eleven_l++;
            twenty_l++;
        }
        if((twenty_w>=21||twenty_l>=21)&&(twenty_w-twenty_l>=2||twenty_l-twenty_w>=2))
        {
            twen_num++;
            record[twen_num][0]=twenty_w;
            record[twen_num][1]=twenty_l;
            twenty_w=0;
            twenty_l=0;
        }
        if((eleven_w>=11||eleven_l>=11)&&(eleven_w-eleven_l>=2||eleven_l-eleven_w>=2))
        {
            printf("%d:%d\n",eleven_w,eleven_l);
            eleven_w=0;
            eleven_l=0;
        }
        c=getchar();
    }
    if(eleven_w!=0||eleven_l!=0)
    {
        printf("%d:%d\n",eleven_w,eleven_l);
    }
    printf("\n");
    if(twenty_w!=0||twenty_l!=0)
    {
        twen_num++;
        record[twen_num][0]=twenty_w;
        record[twen_num][1]=twenty_l;
    }
    for(int i=1;i<=twen_num;i++)
    {
        printf("%d:%d\n",record[i][0],record[i][1]);
    }
    return 0;
}