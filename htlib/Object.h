//
// Object.h
//
// (c) Copyright 1993, San Diego State University -- College of Sciences
//       (See the COPYRIGHT file for more Copyright information)
//
// This baseclass defines how an object should behave.
// This includes the ability to be put into a list
//
// $Id: Object.h,v 1.1 1997/02/03 17:11:04 turtle Exp $
//
// $Log: Object.h,v $
// Revision 1.1  1997/02/03 17:11:04  turtle
// Initial revision
//
//
#ifndef	_Object_h_
#define	_Object_h_

#include "lib.h"

class String;

class Object
{
public:
	//
	// Constructor/Destructor
	//
					Object();
	virtual			~Object();

	//
	// To ensure a consistent comparison interface and to allow comparison
	// of all kinds of different objects, we will define a comparison functions.
	//
	virtual int		compare(Object *);

	//
	// To allow a deep copy of data structures we will define a standard interface...
	// This member will return a copy of itself, freshly allocated and deep copied.
	//
	virtual Object	*Copy();

	//
	// Persistent storage routines.
	//
	virtual void	Serialize(String &);
	virtual void	Deserialize(String &, int &index);

protected:
};


#endif
