#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

unsigned long long time;
char s[65];
int num_time[10],alp_time[27];

int main(void)
{
    int dif_char=0;
    int current_real_num=1;
    int flag=0;

    for(int i=0;i<10;i++) num_time[i]=-1;
    for(int i=0;i<27;i++) alp_time[i]=-1;
    
    /*for(int i=0;i<10;i++) printf("%d ",num_time[i]);
    printf("\n");
    for(int i=0;i<27;i++) printf("%d ",alp_time[i]);*/
    scanf("%s",s);
    //for(int i=0;i<strlen(s);i++) printf("%c",s[i]);

    
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i])&&num_time[s[i]-'0']==-1)
        {
            dif_char++;
            if(dif_char==2) 
            {
                num_time[s[i]-'0']=0;
            }
            else num_time[s[i]-'0']=current_real_num++;
            
        }
        if(isalpha(s[i])&&alp_time[s[i]-'a']==-1)
        {
            dif_char++;
            if(dif_char==2) 
            {
                alp_time[s[i]-'a']=0;
            }
            else alp_time[s[i]-'a']=current_real_num++;
        }
    }

    /*for(int i=0;i<10;i++) printf("%d ",num_time[i]);
    printf("\n");
    for(int i=0;i<27;i++) printf("%d ",alp_time[i]);
    */
    //printf("%d",dif_char);
    if(dif_char==1) dif_char=2;
    /*int len=strlen(s)-1;
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        {
            //printf("%d %d \n",num_time[s[i]-'0'],(int)(pow(dif_char,len)+0.5));
            time+=num_time[s[i]-'0']*(int)(pow(dif_char,len)+0.5);
        }
        
        else
        {
            //printf("%d %d \n",alp_time[s[i]-'a'],(int)(pow(dif_char,len)+0.5));
            time+=alp_time[s[i]-'a']*(int)(pow(dif_char,len)+0.5);
        }
        
        len--;
    }*/
    for(int i=0;i<strlen(s);i++)
    {
        if(isdigit(s[i]))
        time=time*dif_char+num_time[s[i]-'0'];
        else
        time=time*dif_char+alp_time[s[i]-'a'];
    }
    printf("%llu",time);
    
    return 0;
}