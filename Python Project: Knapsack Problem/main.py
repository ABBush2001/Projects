#define our budget
budget = 100

#read in our file line by line
f = open("items.csv", "r")
i = 0

#create lists to hold the names, prices and values of the items
name = []
price = []
value = []

for line in f:
	#skip the first line, which is just the names of the columns in the csv
	if i > 0:
		x = line.split(",")
		name.append(x[0])
		price.append(x[1])
		value.append(x[2])
	i = i + 1		

f.close()

#create a 2d array, c[n+1][budget + 1], which will store our optimal solution
c = [[0 for x in range(budget + 1)] for x in range(len(price) + 1)]

#create a nested for-loop, where the rows i represents our items and our columns j represent our budget from 0 to 100
for i in range(len(price) + 1): 
	for j in range(budget + 1): 
		#if we are in the 0th row or 0th column, initialize the cell to 0
		if i == 0 or j == 0: 
			c[i][j] = 0
		#if the price of the item currently being considered is less than our current budget
		elif int(price[i-1]) <= j: 
			#if the total value from including the item in our solution is greater than if we don't include the item, set the next cell equal
			#to the value of the item plus the value of the item at the cell where the budget j = j - the cost of the item.
			#Otherwise, set the next cell equal to the above cell
			c[i][j] = max(int(value[i-1]) + c[i-1][j-int(price[i-1])],  c[i-1][j])
		#if the price of an item is greater than the current budget, set the next cell equal to the above cell
		else: 
			c[i][j] = c[i-1][j]

#now that our table is complete, print the optimal solution
print("Optimal value: %d\n" % (c[len(price)][100]))

#print out the names of all the items in our solution

#items_list = the list of all the items in our solution
#z = the optimal solution for our list of items
#y = our budget
items_list = []
z = c[len(price)][100]
y = budget

#for-loop will iterate backwards, starting with the last item in our list
for i in range(len(price), 0, -1):
	#if the optimal solution is less than zero
	if z <= 0:
		break
	#if the optimal solution is equal to the solution at the row above it, continue on to that row
	if z == c[i-1][y]:
		continue
	#if the row above z does not equal z
	else:
		#add the item to our items_list
		items_list.append(name[i-1])

		#remove the item's value and price from z and y so that the next loop iteration will only
		#consider all the items in the optimal solution aside from the one we just found
		z = z - int(value[i-1])
		y = y - int(price[i-1])

#print out the list of items in our solution
for i in range(len(items_list) - 1, 0, -1):
	print(items_list[i])
