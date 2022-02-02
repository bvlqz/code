class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        transposedMatrix = [*zip(*matrix)]

        for row in matrix:
            if not len(set(row)) == len(row): return False

        for row in transposedMatrix:
            if not len(set(row)) == len(row): return False

        return True
