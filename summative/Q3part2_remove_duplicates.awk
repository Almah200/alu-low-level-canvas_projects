#!/usr/bin/awk -f

# Remove  duplicate Lines
# run this 2 commands to ge the output
# 1. chmod +x remove_duplicates.awk
# 2. ./remove_duplicates.awk candidates > unique_candidate.txt
{
        if (!seen[$0]++) {
                print $0;
        }
}
