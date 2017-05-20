import math
data = int(input())

for d in range(data):
    x = int(input())
    n = math.ceil((-1+math.sqrt(1+8*x))/(2))
    highest = int((n*(n+1))/2)

    if(n % 2 == 0):
    	num = n-(highest-x)
    	denom = 1+(highest-x)
    	print("TERM ", x, " IS ", num,"/",denom, sep="")
    else:
    	num = 1 + (highest-x)
    	denom = n-(highest-x)
    	print("TERM ", x, " IS ", num,"/",denom, sep="")  
