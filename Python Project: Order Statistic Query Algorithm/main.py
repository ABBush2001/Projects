import sys
import os
import math
import random

#create a class for a whataburger location
class whataburgerLocation:

	def __init__(self, storeID, address, city, state, zipCode, lat, lon):
		self.storeID = int(storeID)
		self.address = str(address)
		self.city = str(city)
		self.state = str(state)
		self.zipCode = int(zipCode)
		self.lat = float(lat)
		self.lon = float(lon)

	#create function to get the distance
	def computeDistance(self, otherLat, otherLon):
		radiusOfTheEarthInMiles = 3958.8

		lat1 = math.radians(float(self.lat))
		lat2 = math.radians(otherLat)
		lon1 = math.radians(float(self.lon))
		lon2 = math.radians(otherLon)

		a = math.pow(math.sin((lat2 - lat1) / 2), 2) + math.cos(lat1)*math.cos(lat2)*math.pow(math.sin((lon2 - lon1)/2), 2)
		c = 2*math.atan2(math.sqrt(a), math.sqrt(1-a))
		return (radiusOfTheEarthInMiles * c) 	

#create a class for a queries
class whataburgerQuery:

	def __init__(self, lat, lon, numStores):
		self.lat = float(lat)
		self.lon = float(lon)
		self.numStores = int(numStores)


#function for random partition
def randPartition(arr, low, high):
	
	#choose a random pivot
	r = random.randint(low, high)
	temp = arr[high]
	arr[high] = arr[r]
	arr[r] = temp

	#now partition
	x = arr[high]
	i = low - 1

	for j in range(low, high):
		if arr[j] <= x:
			i += 1
			temp = arr[i]
			arr[i] = arr[j]
			arr[j] = temp

	temp = arr[i + 1]
	arr[i + 1] = arr[high]
	arr[high] = temp

	return (i+1)

#function for random select
def randSelect(arr, p, q, i):
	if p == q:
		return arr[p]
	r = randPartition(arr, p, q)
	k = r - (p - 1)
	
	if i == k:
		return arr[r]
	if i < k:
		return randSelect(arr, p, r-1, i)
	else:
		return randSelect(arr, r+1, q, i-k)


#start by reading in the whataburger info and place it into an array-like structure

f = open("WhataburgerData.csv", "r")

whataList = []
count = 0

#read in each line
for line in f:
	if count > 0:
		x = line.split(",")
		whataObject = whataburgerLocation(x[0], x[1], x[2], x[3], x[4], x[5], x[6])
		whataList.append(whataObject)
	count += 1

f.close()

#read in queries and store them into their own array
q = open("Queries.csv", "r")

whataQuery = []
count = 0

for line in q:
	if count > 0:
		y = line.split(",")
		whataQueryObject = whataburgerQuery(float(y[0]), float(y[1]), int(y[2]))
		whataQuery.append(whataQueryObject)
	count += 1

q.close()

#for each query, calculate the distance for each whataburger location
for i in whataQuery:
	whataDistance = []

	#for each query, create a list of each distance
	for j in range(0, len(whataList)):
		whataDistance.append(whataList[j].computeDistance(float(i.lat), float(i.lon)))

	#now that we have a list of each store's distance from our query coordinates, we use random selection algorithm to find the
	#farthest store from our query
	farthestStore = randSelect(whataDistance, 0, len(whataDistance)-1, i.numStores)
	
	#now that we have the farthest store distance, we can get all the stores that are closer
	whataStoreDistance = []
	
	for k in whataDistance:
		if k <= farthestStore:
			whataStoreDistance.append(k)

	whataStoreDistance.sort()
	
	#lastly, we can print out our results
	print("\n")
	print("The %d closest Whataburgers to (%lf, %lf):" % (i.numStores, i.lat, i.lon))
	
	for m in whataStoreDistance:
		for n in whataList:
			if n.computeDistance(float(i.lat), float(i.lon)) == m:
				print("Whataburger #%d. %s, %s, %s, %d. - %.2f miles." % (n.storeID, n.address, n.city, n.state, n.zipCode, m))
