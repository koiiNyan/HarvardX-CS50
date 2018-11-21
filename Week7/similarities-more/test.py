from enum import Enum

class Operation(Enum):
    """Operations"""

    DELETED = 1
    INSERTED = 2
    SUBSTITUTED = 3

    def __str__(self):
        return str(self.name.lower())


def distances(a, b):

    matrix = [[(0, None) for x in range(len(b) + 1)] for y in range(len(a) + 1)]

    for i in range(1, len(a) + 1):
        matrix[i][0] = (i, Operation.DELETED)

    for j in range(1, len(b) + 1):
        matrix[0][j] = (j, Operation.INSERTED)

    for i in range(1, len(a) + 1):
        for j in range(1, len(b) + 1):
            # Unpacking tuple
            deletion_cost, _ = matrix[i - 1][j]
            insertion_cost, _ = matrix[i][j - 1]
            substitution_cost, _ = matrix[i - 1][j - 1]

            deletion_cost += 1
            insertion_cost += 1

            if a[i - 1] != b[j - 1]:
                substitution_cost += 1


            if deletion_cost <= insertion_cost and deletion_cost <= substitution_cost:
                matrix[i][j] = (deletion_cost, Operation.DELETED)
            elif insertion_cost <= deletion_cost and insertion_cost <= substitution_cost:
                matrix[i][j] = (insertion_cost, Operation.INSERTED)
            else:
                matrix[i][j] = (substitution_cost, Operation.SUBSTITUTED)

    return matrix

a = 'cat'
b = 'cat'
print(distances(a,b))
