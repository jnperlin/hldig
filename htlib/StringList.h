//
// StringList.h
//
// $Id: StringList.h,v 1.1 1997/02/03 17:11:04 turtle Exp $
//
// $Log: StringList.h,v $
// Revision 1.1  1997/02/03 17:11:04  turtle
// Initial revision
//
//
#ifndef _StringList_h_
#define _StringList_h_

#include "Object.h"
#include "List.h"
#include "String.h"


class StringList : public List
{
public:
    //
    // Construction/Destruction
    //
    StringList();
    ~StringList();

    //
    // Creation of a String from a string or String
    //
    StringList(char *, char sep = '\t');
    StringList(String &, char sep = '\t');
    StringList(char *, char *sep);
    StringList(String &, char *sep);

    int			Create(char *, char sep = '\t');
    int			Create(String &, char sep = '\t');
    int			Create(char *, char *sep);
    int			Create(String &, char *sep);

    //
    // Standard List operations...
    //
    void		Add(char *);
    void		Add(Object *obj);
    void		Insert(char *, int pos);
    void		Insert(Object *obj, int pos);
    void		Assign(char *, int pos);
    void		Assign(Object *obj, int pos);
    int			Remove(int pos);
    int			Remove(Object *obj);

    //
    // Since we know we only store strings, we can reliably sort them.
    // If direction is 1, the sort will be in descending order
    //
    void		Sort(int direction = 0);
	
    //
    // Getting at the parts of the StringList
    //
    char		*operator [] (int n);

private:
};

#endif
