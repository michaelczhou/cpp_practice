#!/usr/bin/perl 
#===============================================================================
#
#         FILE:  dispatcher_client.pl
#
#        USAGE:  ./dispatcher_client.pl  
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
#      CREATED:  2011年06月14日 12时25分51秒
#     REVISION:  ---
#===============================================================================

use strict;
use warnings;
use Getopt::Long;
use Pod::Usage;
use LWP::Simple;

my $man = 0;
my $help = 0;
my $add_file = "a.xml";
my $del_file = "a.del";
my $port = 3088;
my $ip = "localhost";
my $timestamp=0;

GetOptions('help|h' => \$help,
           'man'    => \$man,
           'add|a=s'  => \$add_file,
           'del|d=s'  => \$del_file,
           'port|p=i' => \$port,
           'ip|i=s'   => \$ip,
           'timestamp|t=i' => \$timestamp) or pod2usage(-verbose => 0);
pod2usage(-verbose => 1) if $help;
pod2usage(-verbose => 2) if $man;
pod2usage(-verbose => 0, -msg => "add_file is not accessable") if (! -e $add_file);
pod2usage(-verbose => 0, -msg => "del_file is not accessable") if (! -e $del_file);
pod2usage(-verbose => 0, -msg => "timestamp must be specified") if ! $timestamp;

#load del to hash map
my $auction_id;
my $user_id;
my %del_hash;
#print $del_file, "\n";
open DEL_FILE, "$del_file" or die "Can not open file: $!";
while (<DEL_FILE>) {
    chomp;
    ($auction_id, $user_id) = split(/\x01/);
    #print $auction_id, " ", $user_id, "\n";
    $del_hash{$auction_id} = $user_id;
}
close DEL_FILE;
#process add file and delete corresponding record in hash map
my $url;
my $buf;
my $key;
my $value;
my $content;
open ADD_FILE, "$add_file" or die "Can not open file: $!";
while (<ADD_FILE>) {
    $buf = substr($_, 0, -2); #remove \n
    if (index($buf, "<doc>") != -1) {
        $url = "http://$ip\:$port/bin/update?auction?version=$timestamp&type=add";
    } elsif (index($buf, "</doc>") != -1) {
        #send to http
        print $url, "\n";
        $content = get($url);
        if (defined $content && index ($content, "<errno>0</errno>") != -1) {
            print "sucess to process add nid: $auction_id\n";
        } else {
            print "fail to process add nid: $auction_id\n";
        } 
        next;
    }else {
        if (index($buf, "nid") != -1) {
            ($key, $value) = split(/=/, $buf);
            delete $del_hash{$value};
            $auction_id = $value;
        }
        $url .= "&$buf";
    }
}
close ADD_FILE;
#process record in hash map
while (($auction_id, $user_id) = each %del_hash) {
    #print $auction_id, " ", $user_id, "\n";
    $url = "http://$ip\:$port/bin/update?auction?version=$timestamp&type=del&nid=$auction_id&user_id=$user_id";
    $content = get($url);
    if (defined $content && index ($content, "<errno>0</errno>") != -1) {
        print "sucess to process del nid: $auction_id\n";
    } else {
        print "fail to process del nid: $auction_id\n";
    } 
}

__END__

=head1 NAME

dispatcher_client.pl - client of dispatcher for ksearch

=head1 SYNOPSIS

./dispatcher_client.pl -a add.xml -d del.xml -p 3088 -i localhost -t 1308040611

=head1 DESCRIPTION

B<This program> will read add.xml and del.xml, transform to url and 
send to dispatcher

=head1 AUTHOR

jiye (jiye@taobao.com)

=cut

