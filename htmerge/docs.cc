//
// docs.cc
//
// Implementation of newclass
//
// $Log: docs.cc,v $
// Revision 1.1  1997/02/03 17:11:07  turtle
// Initial revision
//
//
#if RELEASE
static char RCSid[] = "$Id: docs.cc,v 1.1 1997/02/03 17:11:07 turtle Exp $";
#endif

#include "htmerge.h"


//*****************************************************************************
// void convertDocs(char *doc_db, char *doc_index)
//
void
convertDocs(char *doc_db, char *doc_index)
{
    Database	*index = Database::getDatabaseInstance();
    int			document_count = 0;
    int			remove_unused = config.Boolean("remove_bad_urls");
    DocumentDB	db;
    List		*urls;

    if (index->OpenReadWrite(doc_index, 0664) == NOTOK)
    {
	reportError(form("Unable to create document index '%s'", doc_index));
    }
    if (access(doc_db, R_OK) < 0)
    {
	reportError(form("Unable to open document database '%s'", doc_db));
    }

    //
    // Start the conversion by going through all the URLs that are in
    // the document database
    //
    db.Open(doc_db);
    urls = db.URLs();
	
    urls->Start_Get();
    String		*url;
    String		id;
    while (url = (String *) urls->Get_Next())
    {
	DocumentRef	*ref = db[url->get()];
	if (!ref)
	    continue;
	id = 0;
	id << ref->DocID();
	if (remove_unused && discard_list.Exists(id))
	{
	    //
	    // This document is not valid anymore.  Remove it
	    //
	    db.Delete(url->get());
	}
	else
	{
	    index->Put(id, ref->DocURL(), strlen(ref->DocURL()));

	    document_count++;
	    if (verbose && document_count % 10 == 0)
	    {
		cout << "htmerge: " << document_count << '\r';
		cout.flush();
	    }
	}
    }
    if (verbose)
	cout << "\n";
    if (stats)
	cout << "htmerge: Total documents: " << document_count << endl;

    index->Close();
    delete urls;
    db.Close();
}


