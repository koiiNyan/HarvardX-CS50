from enum import Enum


class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):
    """Calculate edit distance from a to b"""

    """TODO
    distances returns a 2D list matrix, where matrix[i][j] is a tuple of:
          edit distance between the first i characters of a and the first j characters of b
          last operation taken in optimal sequence
    Distance - lowest cost of turning string a into string b
    Cost is measured in number of operations
    Types of operations:
      INSERTION: add a character
      DELETION: remove a character
      SUBSTITUTION: replace a character with another
    edit distance between a and b is matrix[len(a)][len(b)]

    ! Edit Distance Algorithm !
    cost[i][j] is min of (Considering the last operation)
      Deletion: cost[i - 1][j] + 1
      Insertion: cost[i][j - 1] + 1
      Substitution:
          cost[i - 1][j - 1] if ith character of a is jth character of b
          cost[i - 1][j - 1] + 1 otherwise

    ! cost !
    in matrix[i][j] store (cost, operation)
    cost is an int to represent the min number of steps it would take to convert
      the first I characters of string A into the firt J characters of string B
    operation is going to be that LAST operation:
      Operation.DELETED, Operation.INSERTED, Operation.SUBSTITUTED
          For matrix[0][0], operation is None -> matrix[0][0] = (0, None)

    ! Calculating Edit Distance !
    Set up 2D list
    Add values for base cases (first row and first column)
    Fill in the other entries in the table"""


    # Initializing matrix
    # Adding + 1 to len so to have the first (0,0) row-column for 2 empty strings
    matrix = [[(0, None) for x in range(len(b) + 1)] for y in range(len(a) + 1)]

    # Filling the matrix with base cases (deletion and insertion)
    # Columns
    # len + 1 so we can go till the very last char of the string (including the first elem, which is 0, None always
    # (as there are 2 empty strings at 0 every time)
    for i in range(1, len(a) + 1):
        matrix[i][0] = (i, Operation.DELETED)

    # Rows
    for j in range(1, len(b) + 1):
        matrix[0][j] = (j, Operation.INSERTED)

    # Calculating min cost and filling the rest of the matrix
    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):

            # Unpacking tuple with , _
            deletion_cost, _ = matrix[i - 1][j]
            insertion_cost, _ = matrix[i][j - 1]
            substitution_cost, _ = matrix[i - 1][j - 1]

            # Adding cost with each cell / iteration
            deletion_cost += 1
            insertion_cost += 1

            # If characters are different then it'll cost 1 to do the substitution
            if a[i - 1] != b[j - 1]:
                substitution_cost += 1


            # Finding the right operation (the minimum cost)
            # If deletion cost is the min cost
            if deletion_cost <= insertion_cost and deletion_cost <= substitution_cost:
                matrix[i][j] = (deletion_cost, Operation.DELETED)
            # Else if insertion cost is the min cost
            elif insertion_cost <= deletion_cost and insertion_cost <= substitution_cost:
                matrix[i][j] = (insertion_cost, Operation.INSERTED)
            # Else - substitution is the min cost
            else:
                matrix[i][j] = (substitution_cost, Operation.SUBSTITUTED)

    return matrix
