import numpy as np

data = []
with open("bezdekIris.data", "r") as f:
    for line in f:
	data.append(line.split(","))
for y in range(150):
	data[y] = data[y][0:4]
data.remove(data[len(data)-1])
#print data
outfile = open('FormattedData.txt', 'w')
for x in data:
	a, b, c, d = x
	outfile.write('%s %s %s %s\n' %(a, b, c, d))
	#print str(x).strip('[]'), "\n"
