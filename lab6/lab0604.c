#include <stdio.h>
#include <string.h>
#include <ctype.h>


int extract_words(char line[],char words[][25])//当数组作为函数参数传递时，数组名会自动退化为指向其首元素的指针，char words[][25]==char(*words)[25]
{
    int count=0,i=0;
    while(line[i]!='\0')
    {
        if(!isalpha(line[i]))
        {
            i++;
            continue;
        }

        char temp[25];
        int len=0;

        while(isalpha(line[i]))
        {
            temp[len]=tolower(line[i]);
            len++;i++;
        }
        temp[len]='\0';

        if(len>=4)
        {
            int flag=0;

            for(int i=0;i<count;i++)
            {
                if(strcmp(words[i],temp)==0) 
                {
                    flag=1;
                    break;
                }
            }

            if(flag==0)
            {
                for(int i=0;i<len;i++)
                {
                    words[count][i]=temp[i];
                }
                count++;
            }

            
        }
    }
    return count;
}

int main(void)
{
    char line1[100000],line2[100000];
    char a[1005][25],b[1005][25];
    char result[1005][25];
    int final_num=0;

    fgets(line1,sizeof(line1),stdin);
    fgets(line2,sizeof(line2),stdin);

    int n1=extract_words(line1,a);
    int n2=extract_words(line2,b);

    //for(int i=0;i<n1;i++) printf("%s\n",a[i]);
    //for(int i=0;i<n2;i++) printf("%s\n",b[i]);

    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(strcmp(a[i],b[j])==0)
            {
                strcpy(result[final_num],a[i]);
                final_num++;
            }
        }
    }
    //用冒泡法排序result
    for(int i=0;i<final_num-1;i++)
    {
        for(int j=0;j<final_num-1-i;j++)
        {
            if(strcmp(result[j],result[j+1])>0)
            {
                char tmp[25];
                strcpy(tmp,result[j]);
                strcpy(result[j],result[j+1]);
                strcpy(result[j+1],tmp);
            }
        }
    }
    for(int i=0;i<final_num;i++)
    {
        printf("%s\n",result[i]);
    }
    return 0;
}