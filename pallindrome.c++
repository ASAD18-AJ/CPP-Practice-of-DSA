#include <bits/stdc++.h>

// check iof the character is valid or not

bool check_character(char ch)
{

    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {

        return 1;
    }

    else
    {

        return 0;
    }
}

// covert uppercase to lower case

char to_lowercase(char ch)
{

    if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {

        return ch;
    }

    else
    {

        return ch - 'A' + 'a';
    }
}

bool checkPalindrome(string s)

{

    int n = s.length();

    int start = 0;

    int end = n - 1;

    while (start < end)
    {

        while (start <= end && !check_character(s[start]))
        {

            start++;
        }

        while (start <= end && !check_character(s[end]))
        {

            end--;
        }

        if (start <= end)
        {

            if (to_lowercase(s[start]) != to_lowercase(s[end]))
            {

                return false;
            }

            start++;

            end--;
        }
    }

    return true;
}