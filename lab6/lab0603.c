#include<stdio.h>
#include<string.h>
char s[2005];
int freq[26];
int max;
int main(void)
{
    fgets(s,sizeof(s),stdin);
    //printf("%lu\n",strlen(s));
    for(int i=0;i<strlen(s)-1;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            freq[s[i]-'a']++;
        else if(s[i]>='A'&&s[i]<='Z')
            freq[s[i]-'A']++;
    }
    max=0;
    for(int i=0;i<26;i++)
    {
        if(freq[i]>max)
            max=freq[i];
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]==max)
            printf("%c ",i+'a');
    }
    printf("%d",max);
    return 0;
}