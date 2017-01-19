''' A Python program to generate frequent datasets for apriori algorithm
	Author - AB
	Date - 4Jan2017'''

import itertools

# basket contains enumerated datatypes
#	1 --> Bread
#	2 --> Milk
#	3 --> Diapers
#	4 --> Beer
#	5 --> Eggs
#	6 --> Cola
basket = {1,2,3,4,5,6}

# Input from text file 'input.txt'. Contains rows of numbers 
# corresponding to the items in each transaction
file = open('input.txt','r')
dataset = file.read()
dataset = dataset.split()

#print count

# A function to read the file
def readfile():
	bucket = []
	k = 0
	for line in open('input.txt'):
		bucket.append(line)

	for k in range(0,len(bucket)):
		bucket[k] = bucket[k].split()
		bucket[k] = map(int,bucket[k])
	#print len(bucket) 
	#print bucket 
	return bucket
	# bucket is set of arrays

# Function call for readfile
trans = readfile()
#print trans

# A function to count the frequency in the first iteration
def countFirstFrequency(b,t):
	count = [0,0,0,0,0,0]
	for each in b:
		for item in t:
			if each in item:
				count[each-1] += 1
	return count

# A list comprehension approach to delete all instance of values
def deleteAllInstance(s,v):
	newList = []
	for each in s:
		if each != v:
			newList.append(each)
	return newList

# A function to prune the dataset
def prune(s,items,minSup):
	#rem = []
	for i in range(0,len(s)):
		if float(s[i]/5.0) <= minSup:
			items[i] = 0
			s[i] = 0
	#print rem
	s = deleteAllInstance(s,0)
	items = deleteAllInstance(items,0)
	#print rem
	#for i in range(0,len(rem)):
	#	items.remove(rem[i])
	return s, items

# A function to generate candidates
# Makes use of itertools
# combinations returns k combinations of the values of the array
# Refer - https://docs.python.org/2/library/itertools.html
def candidateGen(i,k):
	can = []
	can = itertools.combinations(i,k)
	#for x in i:
	#	for y in f:
	#		if x != y:
	#			can.append((x,y))
	can = list(set(can))
	return can


# Count frequency of the items in subsequent iterations
def countFrequency(c,t):
	count = [0]*len(c)
	for each in c:
		for item in t:
			if set(each).issubset(item):
				count[c.index(each)] += 1
	return count

# Instead of incrementing the support count, I have taken the average
# as it comfortably eliminates the non-frequent itemsets
# also it is easier to implement
def updateMinSup(f):
	avg = float(sum(f)/len(f))
	return avg/5

# driver function to generate the itemsets
def generate():
	k = 1
	minSup = 0.4
	frequencyOneItemSet = list(basket)
	frequencyOne = countFirstFrequency(frequencyOneItemSet,trans)
	frequencyOne, frequencyOneItemSet = prune(frequencyOne,frequencyOneItemSet,minSup)
	totalSet = set(frequencyOneItemSet)

	candidateSet = frequencyOneItemSet
	while len(candidateSet) != 0:
		print 'Frequency',k,'Itemsets'
		print set(candidateSet)
		k += 1
		candidateSet = candidateGen(frequencyOneItemSet,k)
		candidateFrequency = countFrequency(candidateSet,trans)
		minSup = updateMinSup(candidateFrequency)
		candidateFrequency, candidateSet = prune(candidateFrequency,candidateSet,minSup)
		totalSet = totalSet | set(candidateSet)

	print totalSet

generate()