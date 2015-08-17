/**

This program prompts a user for their name.  It then outputs the user's initials
in uppercase letters.

Michael Pease
Aug. 17, 2015

**/

#include<cs50.h>
#include<stdio.h>
#include<ctype.h>
#include<string.h>

//converts user key to all uppercase letters
string stringToUpper(string name)
{
    for (int i = 0; i < strlen(name); i++)
        name[i] = toupper(name[i]);
    return name;
}

int main(void)
{
    int index = 0;
    char initials[10];
    string name = GetString();
    name = stringToUpper(name);
    
    for (int i = 0; i < strlen(name); i++)
    {
        //takes first letter of name and adds it to initials
        if (i == 0)
        {
            initials[index] = name[i];
            index++;
        }
        
        
        //if the previous char was a space, adds current char to initials
        if  (i != 0 && name[i-1] == 32)
        {
            initials[index] = name[i];
            index++;
        }
    
    }
    
    initials[index] = '\0';
    printf("%s\n", initials);

    return 0;
}
