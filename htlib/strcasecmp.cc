//
// strcasecmp.cc
//
// Implementation of strcasecmp
//
#include "lib.h"
#include <ctype.h>

//*****************************************************************************
// int mystrcasecmp(char *str1, const char *str2)
//
int mystrcasecmp(char *str1, const char *str2)
{
	while (*str1 && *str2 && tolower(*str1) == tolower(*str2))
	{
		str1++;
		str2++;
	}

	return tolower(*str1) - tolower(*str2);
}


#define tolower(ch)	(isupper(ch) ? (ch) + 'a' - 'A' : (ch))
//*****************************************************************************
// int mystrncasecmp(char *str1, const char *str2, int n)
//
int mystrncasecmp(char *str1, const char *str2, int n)
{
	while (n && *str1 && *str2 && tolower(*str1) == *str2)
	{
		str1++;
		str2++;
		n--;
	}

	return n == 0 ? 0 : tolower(*str1) - *str2;
}


//*****************************************************************************
// char *strdup(char *str)
//
char *strdup(char *str)
{
	char	*p = new char[strlen(str) + 1];
	strcpy(p, str);
	return p;
}


//*****************************************************************************
// char *mystrcasestr(char *s, char *pattern)
//
char *
mystrcasestr(char *s, char *pattern)
{
	int		length = strlen(pattern);

	while (*s)
	{
		if (mystrncasecmp(s, pattern, length) == 0)
			return s;
		s++;
	}
	return 0;
}


