# https://www.hackerrank.com/challenges/time-conversion/problem

def timeConversion(s):
    hour = int(s[0:2])
    
    if s[-2:] == "AM":
        if s[0:2] == "12":
            res = f"0{hour - 12}{s[2:8]}"
            return res
        else:
            return s[0:8]
    else:
        if s[0:2] == "12":
            return s[0:8]
        else:
            res = f"{hour + 12}{s[2:8]}"
            return res