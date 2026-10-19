#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() 
{
    char line[205];       
    char clean[205];   

    while (fgets(line, sizeof(line), stdin) != NULL)//fgets读取多行字符（包括空格等）
    {
        int clean_len = 0;
        
        for (int i = 0; line[i] != '\0'; i++) 
        {
            if (line[i] == '\n' || line[i] == '\r'|| line[i] == ' ') //清除空格/回车符等等
            {
                continue;
            }
            
            clean[clean_len++] = tolower(line[i]);
        }
        clean[clean_len] = '\0'; 
        
        int left = 0;
        int right = clean_len - 1;
        int is_palindrome = 1; 
        int is_sub=1;

        while (left < right) //利用while来双端检测
        {
            if (clean[left] != clean[right]) 
            {
                is_palindrome = 0; 
                break;
            }
            left++;
            right--;
        }

        if (is_palindrome) 
        {
            printf("palindrome\n");
            continue;
        } 


        for(int i=0;i<clean_len;i++)
        {
            for(int j=i+1;j<clean_len;j++)
            {
                left=i;
                right=j;
                while (left < right) 
                {
                    if (clean[left] != clean[right]) 
                    {
                        is_sub = 0; 
                        break;
                    }
                    left++;
                    right--;
                }
                if(left==right&&is_sub)
                {
                    printf("palindromic substring\n");
                    return 0;
                }
                //printf("left=%d,right=%d,is_sub=%d\n",left,right,is_sub);
            }
        }

        printf("whatever\n");
        
    }

    return 0;
}