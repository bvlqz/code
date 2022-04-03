class Solution:
    sequence = []
    
    def collatz(self, n):
        if n == 1:
            self.sequence.append(n)
        elif n % 2 == 0:
            new = n / 2
            self.sequence.append(new)
            self.collatz(new)
        else:
            new = 3 * n + 1
            self.sequence.append(new)
            self.collatz(new)

    
    def solve(self, n):
        self.sequence = []
        self.collatz(n)
        return len(self.sequence)
