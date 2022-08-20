class Solution:
    def sortSentence(self, s: str) -> str:
        asList = s.split(" ")
        asList.sort(key=lambda x: int(x[-1]) - 1)
        asList = [string[:-1] for string in asList]
        return " ".join(asList)
