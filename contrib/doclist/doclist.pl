#!/usr/local/bin/perl

##
## doclist.pl  (C) 1995 Andrew Scherpbier
##
## This program will list the information in the documentdb generated by htdig.
##

use GDBM_File;

$dbfile = $ARGV[0];

tie(%docdb, GDBM_File, $dbfile, GDBM_READER, 0) || die "Unable to open $dbfile: $!";


while (($key, $value) = each %docdb)
{
    next if $key =~ /^nextDocID/;
    %record = parse_ref_record($value);
    print "Title:        $record{'TITLE'}\n";
    print "Descriptions: $record{'DESCRIPTIONS'}\n";
    print "URL:          $record{'URL'}\n";
    print "\n";
}

sub parse_ref_record
{
    local($value) = @_;
    local(%rec, $length, $count, $result);

    while (length($value) > 0)
    {
	$what = unpack("C", $value);
	$value = substr($value, 1);
	if ($what == 0)
	{
	    # ID
	    $rec{"ID"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 1)
	{
	    # TIME
	    $rec{"TIME"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 2)
	{
	    # ACCESSED
	    $rec{"ACCESSED"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 3)
	{
	    # STATE
	    $rec{"STATE"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 4)
	{
	    # SIZE
	    $rec{"SIZE"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 5)
	{
	    # LINKS
	    $rec{"LINKS"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 6)
	{
	    # IMAGESIZE
	    $rec{"IMAGESIZE"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 7)
	{
	    # HOPCOUNT
	    $rec{"HOPCOUNT"} = unpack("i", $value);
	    $value = substr($value, 4);
	}
	elsif ($what == 8)
	{
	    # URL
	    $length = unpack("i", $value);
	    $rec{"URL"} = unpack("x4 A$length", $value);
	    $value = substr($value, 4 + $length);
	}
	elsif ($what == 9)
	{
	    # HEAD
	    $length = unpack("i", $value);
	    $rec{"HEAD"} = unpack("x4 A$length", $value);
	    $value = substr($value, 4 + $length);
	}
	elsif ($what == 10)
	{
	    # TITLE
	    $length = unpack("i", $value);
	    $rec{"TITLE"} = unpack("x4 A$length", $value);
	    $value = substr($value, 4 + $length);
	}
	elsif ($what == 11)
	{
	    # DESCRIPTIONS
	    $count = unpack("i", $value);
	    $value = substr($value, 4);
	    $result = "";
	    foreach (1 .. $count)
	    {
		$length = unpack("i", $value);
		$result = $result . unpack("x4 A$length", $value) . "";
		$value = substr($value, 4 + $length);
	    }
	    chop $result;
	    $rec{"DESCRIPTIONS"} = $result;
	}
	elsif ($what == 12)
	{
	    # ANCHORS
	    $count = unpack("i", $value);
	    $value = substr($value, 4);
	    $result = "";
	    foreach (1 .. $count)
	    {
		$length = unpack("i", $value);
		$result = $result . unpack("x4 A$length", $value) . "";
		$value = substr($value, 4 + $length);
	    }
	    chop $result;
	    $rec{"ANCHORS"} = $result;
	}
	elsif ($what == 13)
	{
	    # EMAIL
	    $length = unpack("i", $value);
	    $rec{"EMAIL"} = unpack("x4 A$length", $value);
	    $value = substr($value, 4 + $length);
	}
	elsif ($what == 14)
	{
	    # NOTIFICATION
	    $length = unpack("i", $value);
	    $rec{"NOTIFICATION"} = unpack("x4 A$length", $value);
	    $value = substr($value, 4 + $length);
	}
	elsif ($what == 15)
	{
	    # SUBJECT
	    $length = unpack("i", $value);
	    $rec{"SUBJECT"} = unpack("x4 A$length", $value);
	    $value = substr($value, 4 + $length);
	}
    }
    return %rec;
}
