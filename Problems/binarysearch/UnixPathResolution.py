class Solution:
    def solve(self, path):

        resolved = []

        for directory in path:
            if directory == ".":
                continue

            elif directory == "..":
                if len(resolved) != 0:
                    resolved.pop()
                else:
                    continue

            else:
                resolved.append(directory)
        
        return resolved 
