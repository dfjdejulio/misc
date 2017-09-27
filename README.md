Misc Utilities
==============

I've written a bunch of little programs to help me get things done
over the decades.  May as well stash them here...

iota
----

A trivial command-line program I built for my own use, based on APL's
"iota" operator.

There's really almost nothing to it.  It was useful to me back in the
day when it was harder to do looping and such in shell scripts.

Since it doesn't have any special dependencies, you can built it by
typing "make iota" even without an Makefile, as long as you have C89
and a decent "make".

bifurcate
---------

I was helping some folks with an experiment, and they needed to split
a list into two equal sized groups without changing the sort order.
So I whipped this up to do the job.

roll
----

A trivial die-rolling program for some quick D&D stuff I was doing once.
In addition to the "3d6" syntax, you can say "3b4d6" to mean "3 best of
4 rolls of a 6-sided die".  So you could roll a 1st edition character by
typing this: "roll -r 6 3b4d6".

jack
----

All work and no play makes Jack a dull boy.

font2mobileconfig.sh
--------------------

So, iOS can use TrueType fonts, but installing them is a pain in the
tuchus.  You can't just install them.  The "normal" way to do this is
for someone with the Apple-provided complex iOS provisioning tools to
build a provisioning profile that contains the font.  But, the format is
actually just a standard XML plist with pretty well-defined keys and values
and stuff, so I wrote this shell script to turn any TTF (or OTF) into
a ".mobileconfig" file that instlals the font in question.

(It's pretty badly written right now, but it gets the job done for me.)

apfs_clone
----------

The APFS filesystem supports cloning files, which means the production of
space-efficient duplicates that use copy-on-write as you modify them.  But
the normal default Unix/POSIX ways of copying files does *not* produce that
kind of clone.  You have to use a new system call to get the cloning behavior.
So, I whipped up a trivial command-line tool that's not much more than a wrapper
around one of those system calls.
