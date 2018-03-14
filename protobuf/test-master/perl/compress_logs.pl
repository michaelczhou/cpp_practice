#!/usr/bin/perl 
#===============================================================================
#
#         FILE:  compress_logs.pl
#
#        USAGE:  ./compress_logs.pl  
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
#      CREATED:  2011年06月15日 09时36分13秒
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;

use Time::Local;

my $log_dir = "./logs";
my $log_pattern = '^.*log.([0-9]{4})-([0-9]{2})-([0-9]{2})$';
my $keep_days = 2;

&compress_logs ($log_dir, $log_pattern);

sub compress_logs()
{
    my ($log_dir, $log_pattern) = @_;

    opendir(DIR, $log_dir) || die "open dir $log_dir failed!";
    my @all_files = grep !/^\.\.?$/, readdir DIR;

    my ($sec, $min, $hour, $mday, $mon, $year, $wday, $yday, $isdst) = localtime(time);
    my $today_days = timelocal(0,0,0,$mday, $mon, $year+1900)/86400;

    chdir($log_dir);

    foreach (@all_files) {
        if ($_ =~ /$log_pattern/) {
            my $log_file = "$log_dir/$_";
            my $file_days = timelocal(0, 0, 0, $3, $2-1, $1)/86400;
            if (($today_days - $file_days) > $keep_days) {
                print "gzip $log_file\n";
                #system ("gzip $log_file");
            } else {
                print "leave $log_file\n";
            }
        }
    }
}


