//
// Configuration.h
//
// This class provides an object lookup table.  Each object in the Configuration
// is indexed with a string.  The objects can be returned by mentioning their
// string index.
//
// $Id: Configuration.h,v 1.1 1997/02/03 17:11:04 turtle Exp $
//
// $Log: Configuration.h,v $
// Revision 1.1  1997/02/03 17:11:04  turtle
// Initial revision
//
//
#ifndef	_Configuration_h_
#define	_Configuration_h_

#include "Dictionary.h"
#include <htconfig.h>

class String;


struct ConfigDefaults
{
	char	*name;
	char	*value;
};


class Configuration : public Object
{
public:
	//
	// Construction/Destruction
	//
					Configuration();
					~Configuration();

	//
	// Adding and deleting items to and from the Configuration
	//
	void			Add(char *name, char *value);
	void			Add(char *str);
	int				Remove(char *name);

	//
	// Let the Configuration know how to parse name value pairs
	//
	void			NameValueSeparators(char *s);
	
	//
	// We need some way of reading in the database from a configuration file
	//
	int				Read(char *filename);

	//
	// Searching can be done with the Find() member or the array indexing
	// operator
	//
	char			*Find(char *name);
	char			*operator[](char *name);
	int				Value(char *name, int default_value = 0);
	double			Double(char *name, double default_value = 0);
	int				Boolean(char *name, int default_value = 0);

	//
	// Read defaults from an array
	//
	void			Defaults(ConfigDefaults *);

protected:
	Dictionary		dict;
	String			*separators;
	int				allow_multiple;
};


#endif
