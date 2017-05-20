# your code goes here
import sys
from operator import itemgetter
crowd = []
for line in sys.stdin:
	name, age = line.split()
	crowd.append([name, int(age)*-1])
sorted(crowd, key = itemgetter(1,0))
for person in crowd:
	print(person[0])

	

