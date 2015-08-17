/**

This program converts user-inputted plaintext into ciphertext using a vigenere keyword
that the user also inputs

Michael Pease
Aug. 17, 2015

**/

#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

//function to convert user text to cipher text
string textConversion(string text, string key)
{
    int keyIndex = 0;
    int keyVal = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            //finds how many times to change char 
            keyVal = key[keyIndex] - 97;
            
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                    if (text[i] + keyVal > 'Z')
                    {
                        text[i] = (text[i] + keyVal) - 26;
                        keyIndex++;
                        
                        if (keyIndex == strlen(key))
                            keyIndex = 0;
                    }
                    else
                    {
                        text[i] += keyVal;
                        keyIndex++;
                        
                        if (keyIndex == strlen(key))
                            keyIndex = 0;
                    }
            }        
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                    if (text[i] + keyVal > 'z')
                    {
                        text[i] = (text[i] + keyVal) - 26;
                        keyIndex++;
                        
                        if (keyIndex == strlen(key))
                            keyIndex = 0;
                    }
                    else
                    {
                        text[i] += keyVal;
                        keyIndex++;
                        
                        if (keyIndex == strlen(key))
                            keyIndex = 0;
                    }
            }
        }
    }
    
    return text;
}

//converts user key to all lowercase letters
string stringToLower(string key)
{
    for (int i = 0; i < strlen(key); i++)
        key[i] = tolower(key[i]);
    return key;
}

int main(int argc, string argv[])
{
    string stringToLower(string key);
    string textConversion(string text, string key);
    string text, key;
    int i;
    
    //makes sure only one keyword was typed on the command line 
    if (argc != 2)
    {
        printf("Error! No key typed on command line.\n");
	    return 1;
    }
    
    //makes sure the keyword only consists of letters
    else
        key = stringToLower((argv[1]));
        for (i = 0; i < strlen(key); i++)
        {
            if (!isalpha(key[i]))
            {
                printf("Error! Your keyword must only consist of letters.\n");
                return 1;
            }
        }

	text = GetString();
    textConversion(text, key);

    printf("%s\n", text);

    return 0;
}
