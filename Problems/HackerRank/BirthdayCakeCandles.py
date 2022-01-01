# https://www.hackerrank.com/challenges/birthday-cake-candles/problem

def birthdayCakeCandles(candles):
    maxCandleHeight = 0
    candleCount = {}
    for candle in candles:
        if candle not in candleCount:
            candleCount[candle] = 1
        else:
            candleCount[candle] = candleCount[candle] + 1
        
        if candle > maxCandleHeight:
            maxCandleHeight = candle
    
    return candleCount[maxCandleHeight]