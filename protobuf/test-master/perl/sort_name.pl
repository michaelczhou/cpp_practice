#!/usr/bin/perl 
#===============================================================================
#
#         FILE:  sort_name.pl
#
#        USAGE:  ./sort_name.pl  
#
#  DESCRIPTION:  
#
#      OPTIONS:  ---
# REQUIREMENTS:  ---
#         BUGS:  ---
#        NOTES:  ---
#       AUTHOR:  jiye (taobao), jiye@taobao.com
#      COMPANY:  www.taobao.com
#      VERSION:  1.0
#      CREATED:  2011年06月16日 09时18分32秒
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;

my %last_name = qw{
fred flintstone Wilma Flintstone Barney Rubble
betty rubble Bamm-Bamm Rubble PEBBLES FLINTSTONE
};
sub by_name_insenstive {
    "\L$last_name{$a}" cmp "\L$last_name{$b}" or
    "\L$a" cmp "\L$b"
}
foreach my $key (sort by_name_insenstive keys %last_name) {
    print $key, "\t", $last_name{$key}, "\n";
}
