/**

This program encrypts a user inputed string using a command line specified key

Michael Pease
Aug. 17, 2015

**/

#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

//this function converts plain text to cipher text using user generated key
string convertToCipher(string text, int key)
{

    for (int i = 0; i < strlen(text); i++)
    {
    
        //checks to see if current char is a letter
        if (isalpha(text[i]))
        
            //checks to see if uppercase letter
            if (text[i] >= 'A' && text[i] <= 'Z')
            {
                //if current letter + key goes past Z, wraps back to A
                if (text[i] + key > 'Z')
                    text[i] = (text[i] + key) - 26;
                    
                //else changes letter according to key
                else
                    text[i] = text[i] + key;
            }
            
            //checks to see if lowercase letter        
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                //if current letter + key goes past z, wraps back to a
                if (text[i] + key > 'z')
                    text[i] = (text[i] + key) - 26;
                    
                //else changes letter according to key
                else
                    text[i] = text[i] + key;
            }           
    }
    return text;
}

int main(int argc, string argv[])
{
    int key;
    string text;
    string convertToCipher(string text, int key);
    
    //makes sure usage is correct
    if (argc != 2)
    {
        printf("Error! No command line argument entered.\n");
        return 1;
    }
        
    else
    {
        text = GetString();
        key = atoi(argv[1]);
        
            //checks to make sure key is between 0 and 25
            if (key > 25)
                key = key % 26;
    }
    //prints converted text            
    printf("%s\n", convertToCipher(text, key));
    return 0;
}
