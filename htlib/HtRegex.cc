//
// HtRegex.cc
//
// A simple C++ wrapper class for the system regex routines.
//
// Part of the ht://Dig package   <http://www.htdig.org/>
// Copyright (c) 1999 The ht://Dig Group
// For copyright details, see the file COPYING in your distribution
// or the GNU Public License version 2 or later 
// <http://www.gnu.org/copyleft/gpl.html>
//
// $Id: HtRegex.cc,v 1.2 1999/05/05 00:41:53 ghutchis Exp $
//
//
#include "HtRegex.h"
#include <locale.h>

HtRegex::HtRegex()
{
	compiled = 0;
}

HtRegex::HtRegex(char *str)
{
  set(str);
}

HtRegex::~HtRegex()
{
	if (compiled != 0) regfree(&re);
	compiled = 0;
}

void
HtRegex::set(char * str)
{
	compiled = 0;
	if (str == NULL) return;
	if (strlen(str) <= 0) return;
	if (regcomp(&re, str, REG_EXTENDED|REG_ICASE) == 0)
		compiled = 1;
}

int
HtRegex::match(char * str, int nullpattern, int nullstr)
{
	int	rval;
	
	if (compiled == 0) return(nullpattern);
	if (str == NULL) return(nullstr);
	if (strlen(str) <= 0) return(nullstr);
	rval = regexec(&re, str, (size_t) 0, NULL, 0);
	if (rval == 0) return(1);
	else return(0);
}

