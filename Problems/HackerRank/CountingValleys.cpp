int countingValleys(int steps, string path) {
    int currentAltitude = 0;
    int valleyCount = 0;
    bool insideValley = false;

    for(int i = 0; i < steps; i++)
    {
        if(path[i] == 'D') { currentAltitude -= 1; }
        if(path[i] == 'U') { currentAltitude += 1; }

        if (currentAltitude >= 0)
        {
            insideValley = false; 
            continue;            
        }

        if (insideValley) continue;
        
        if ((currentAltitude < 0) && (!insideValley))
        {
            valleyCount += 1; 
            insideValley = true;
        }
    }
    return valleyCount;
}
