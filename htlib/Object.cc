//
// Object.cc
//
// (c) Copyright 1993, San Diego State University -- College of Sciences
//       (See the COPYRIGHT file for more Copyright information)
//
// Implementation of the Object class
//
// $Log: Object.cc,v $
// Revision 1.1  1997/02/03 17:11:04  turtle
// Initial revision
//
//
#if RELEASE
static char	RCSid[] = "$Id: Object.cc,v 1.1 1997/02/03 17:11:04 turtle Exp $";
#endif

#include "Object.h"
#include <stdio.h>


//***************************************************************************
// Object::Object()
//
Object::Object()
{
}


//***************************************************************************
// Object::~Object()
//
Object::~Object()
{
}


//***************************************************************************
// int Object::compare(Object *)
//
int Object::compare(Object *)
{
	return 0;
}


//***************************************************************************
// Object *Object::Copy()
//
Object *Object::Copy()
{
	return new Object;
}


//***************************************************************************
// void Object::Serialize(String &)
//
void Object::Serialize(String &)
{
}


//***************************************************************************
// void Object::Deserialize(String &, int &)
//
void Object::Deserialize(String &, int &)
{
}


