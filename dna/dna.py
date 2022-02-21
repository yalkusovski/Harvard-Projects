import sys
import csv
import re


def main():

    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit()

    # Filen names
    database = sys.argv[1]
    seq = sys.argv[2]

    # open CSV file
    csv_filename = open(database, "r")
    if not csv_filename:
        print("CSV not loaded")
        sys.exit()

    # Read file to memory
    csv_data = csv.DictReader(csv_filename)

    # Obtain STR list
    fields = csv_data.fieldnames[1:]

    # Open dna sequence
    seq_file = open(seq, "r")
    if not seq_file:
        print("Text file error")
        sys.exit(1)

    # copy in memory
    seq_data = seq_file.read()

    # Close file with sequences
    seq_file.close()

    strs = count(seq_data, fields)

    result = comp(csv_data, strs)

    csv_filename.close()

    if result != False:
        print(result)
    else:
        print('No match')



def comp(csv_database, str):
    for row in csv_database:
        str_value = [int(row[str_name]) for str_name in str]

        if str_value == list(str.values()):
            return row['name']
    return False

def count(seq, fields):

    strs = dict.fromkeys(fields, 0)
    seq_len = len(seq)


    for pos in range(seq_len):

        for str_name in strs:
            j = 0
            while re.match(str_name, seq[pos:]):
                j += 1
                pos += len(str_name)


            if j > strs[str_name]:
                strs[str_name] = j
    return strs

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


main()
