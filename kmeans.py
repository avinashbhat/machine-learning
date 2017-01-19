''' K-MEANS CLUSTERING IMPLEMENTATION 
	BY: AB
	DATE: 31DEC2016
	PROBLEM STATEMENT: Generate 100 measurements of chest size and height of random men.
	                      We want to identify the three T-shirt size for our company. '''

#!/usr/bin/python

import random
import matplotlib.pyplot as py

# A function to select the closest centroid
def chooseClosest(p):
	d1 = ((p[0]-c1[0])**2 + (p[1]-c1[1])**2)**0.5
	d2 = ((p[0]-c2[0])**2 + (p[1]-c2[1])**2)**0.5
	d3 = ((p[0]-c3[0])**2 + (p[1]-c3[1])**2)**0.5
	l = [d1,d2,d3]
	return l.index(min(l))

# A function to define new centroid for a cluster
def updateCentroid(clust):
	xval = 0
	yval = 0
	for i in range(0,len(clust)):
		p = clust[i]
		xval += p[0]
		yval += p[1]
	newCentroid = [(xval/len(clust)),(yval/len(clust))]
	return newCentroid

# A function to cluster the points based on the centroid
def cluster():
	for i in range(0,len(sample)):
		p = sample[i]
		k = chooseClosest(p)
		if k == 0:
			cluster1.append(p)
		elif k == 1:
			cluster2.append(p)
		elif k == 2:
			cluster3.append(p)

# A function to display the clusters
def display(clust,cen,col,mark):
	x = []
	y = []
	for i in range(0,len(clust)):
		p = clust[i]
		x.append(p[0])
		y.append(p[1])
	py.scatter(x,y,color=col,alpha='0.5',marker=mark)
	py.scatter(cen[0],cen[1],color='k',alpha='0.8',marker=mark,s=40)

# Driver function for display
def displayCluster(cen1,cen2,cen3):
	display(cluster1,cen1,'r',"^")
	display(cluster2,cen2,'g',"v")
	display(cluster3,cen3,'b',"o")
	py.show()
	py.close()


# A function to group the sample till it is defined in different groups
# Takes random centroids as paramenters
# 1. Update the centroid using the clusters based on random centroid
# 2. Assign updated cetroid to old centroid
# 3. cluster based on new centroid
# 4. Update centroids based on new cluster
# 5. Do steps 2 to 5 till old and new centroids are equal
def kmeans(c1,c2,c3):
	newC1 = updateCentroid(cluster1)
	newC2 = updateCentroid(cluster2)
	newC3 = updateCentroid(cluster3)
	while newC1!=c1 and newC2!=c2 and newC3!=c3:
		c1 = newC1
		c2 = newC2
		c3 = newC3
		cluster()
		displayCluster(c1,c2,c3)
		newC1 = updateCentroid(cluster1)
		newC2 = updateCentroid(cluster2)
		newC3 = updateCentroid(cluster3)
	print c1,c2,c3


# ----------------BEGIN---------------- #

# Generate sample space
# Chest original sizes from 34-44, sample from 32-47
# Average Indian height is 167cm, sample from 160-180
chest = []
height = []
sample = []
for i in range(0,1000):
	c = random.randint(0,50000)
	h = random.randint(0,200000)
	sample.append((c,h))

# Pick random centroids c1,c2,c3
c1 = random.choice(sample)
c2 = random.choice(sample)
while c2 == c1:
	c2 = random.choice(sample)
c3 = random.choice(sample)
while c2 == c3 and c1 == c3:
	c3 = random.choice(sample)
print c1,c2,c3

cluster1 = []
cluster2 = []
cluster3 = []

# Cluster based on randomly selected points
cluster()
displayCluster(c1,c2,c3)
c1 = [c1[0],c1[1]]
c2 = [c2[0],c2[1]]
c3 = [c3[0],c3[1]]

# Call k-means function with randomly picked centroid
kmeans(c1,c2,c3)