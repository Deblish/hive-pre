#!/usr/bin/perl
use warnings;
use strict;

# Exit unless there are exactly three command-line arguments
die "Usage: program x y density" unless (scalar(@ARGV) == 3);

# Assign command-line arguments to variables
my ($x, $y, $density) = @ARGV;

# Open a file for writing
open(my $fh, '>', 'example2') or die "Could not open file 'example2' $!";

# Print the setup line to the file
print $fh "$y.ox\n";

# Generate and print the grid to the file
for (my $i = 0; $i < $y; $i++) {
    for (my $j = 0; $j < $x; $j++) {
        if (int(rand($y) * 2) < $density) {
            print $fh "o";
        } else {
            print $fh ".";
        }
    }
    print $fh "\n";
}

# Close the filehandle
close $fh;