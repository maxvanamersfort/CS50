import csv
import sys
import re
import numpy as np


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable
    db = sys.argv[1]
    seq = sys.argv[2]

    head = []
    info = []
    dnacount = []

    with open(db, 'r') as csvfile:
        read = csv.reader(csvfile)
        line = 0

        for row in read:
            if line == 0:
                head = row
                line += 1
            else:
                info.append(row)

    with open(seq, 'r') as txtfile:
        sq = txtfile.readline().rstrip("\n")

    # TODO: Read DNA sequence file into a variable
    for i in range(1, len(head)):
        dnacount.append(count(head[i], sq))
    dnacount = np.array(dnacount)

    # TODO: Find longest match of each STR in DNA sequence
    for i in range(len(info)):
        tmp = np.array(info[i][1:])

        if (tmp == dnacount).all():
            name = info[i][0]
            break
        else:
            name = "No Match"

    print(name)

    # TODO: Check database for matching profiles


def count(c, s):
    p = rf'({c})\1*'
    pattern = re.compile(p)
    match = [match for match in pattern.finditer(s)]
    max = 0
    for i in range(len(match)):
        if match[i].group().count(c) > max:
            max = match[i].group().count(c)
    return str(max)


main()


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run