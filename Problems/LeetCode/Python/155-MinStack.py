class MinStack:

    def __init__(self):
        self.stack = []
        self.minVals = []

    def push(self, val: int) -> None:
        if len(self.stack) == 0: 
            minVal = val
            self.minVals.append(val)
        else:
            if self.minVals[-1] > val: 
                self.minVals.append(val)
            else:
                self.minVals.append(self.minVals[-1])

        self.stack.append(val)

    def pop(self) -> None:
        del self.stack[-1]
        del self.minVals[-1]

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.minVals[-1]
