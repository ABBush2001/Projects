#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	fp = fopen("Input.txt", "r");

	if(fp == NULL)
	{
		printf("Error: file failed to open\n");
	}

	else
	{
		//create 3 queues
		Queue line1 = newQueue();
		Queue line2 = newQueue();
		Queue line3 = newQueue();

		/*using a while loop and fscanf, scan in each the 3 elements, time arrived, shopperID, and numItems. put the last 2 into the smallest queue,
		then, for each line after the first, check to see if current time is equal to time arrived, if not, wait until it is and then queue in shortest
		line*/

		int count1 = 0;
		int count2 = 0;
		int count3 = 0;
		int timer = 1;
		int timeArrived;
		int ID;
		int numItems;
		
		while(fscanf(fp, "%d %d %d", &timeArrived, &ID, &numItems) != EOF)
		{


			/*check the current time, remove items until time is reached, then queue new person and dequeue when person runs out of items
			print it*/

			if(timer != timeArrived)
			{
				while(timer != timeArrived)
				{

					//if there are shoppers in line 1
					if(isEmpty(line1) == 0)
					{

						if(line1->head->element.numberOfItems != 0)
						{
							line1->head->element.numberOfItems--;
							count1--;
						}

						else
						{
							printf("Shopper %d finished checking out of line 1 at time %d\n", line1->head->element.shopperID, timer);
							Element *e;
							dequeue(line1, e);
						}
					}

					//shoppers in line 2
					if(isEmpty(line2) == 0)
					{
						if(line2->head->element.numberOfItems != 0)
						{
							line2->head->element.numberOfItems = line2->head->element.numberOfItems - 1;
							count2--;
						}

						else
						{
							printf("Shopper %d finished checking out of line 2 at time %d\n", line2->head->element.shopperID, timer);
							Element *e;
							dequeue(line2, e);
						}
					}

					//shoppers in line 3
					if(isEmpty(line3) == 0)
					{
						if(line3->head->element.numberOfItems != 0)
						{
							line3->head->element.numberOfItems = line3->head->element.numberOfItems - 1;
							count3--;
						}

						else
						{
							printf("Shopper %d finished checking out of line 3 at time %d\n", line3->head->element.shopperID, timer);
							Element *e;
							dequeue(line3, e);
						}
					}

					timer++;
				}
			}

			//if timer equals timeArrived
			if(timer == timeArrived)
			{
				Element e;
				e.shopperID = ID;
				e.numberOfItems = numItems - 1;

				//if line 1 is empty
				if(isEmpty(line1) == 1)
				{
					enqueue(line1, e);
					count1 = count1 + numItems;
				}

				//if line 2 is empty
				else if(isEmpty(line1) == 0 && isEmpty(line2) == 1)
				{
					enqueue(line2, e);
					count2 = count2 + numItems;
				}

				//if line 3 is empty
				else if(isEmpty(line1) == 0 && isEmpty(line2) == 0 && isEmpty(line3) == 1)
				{
					enqueue(line3, e);
					count3 = count3 + numItems;
				}

				//if no lines are empty
				else if(isEmpty(line1) == 0 && isEmpty(line2) == 0 && isEmpty(line3) == 0)
				{
				
					//if all lines have equal items to be checked out
					if(count1 == count2 && count2 == count3)
					{
						enqueue(line1, e);
						count1 = count1 + numItems;
					}

					//lines 2 and 3 have an equal number of items, which is less than items in 1
					else if(count2 == count3 && count2 < count1)
					{
						enqueue(line2, e);
						count2 = count2 + numItems;
					}

					//lines 2 and 3 have an equal number of items, which is more than those in 1
					else if(count2 == count3 && count1 < count2)
					{
						enqueue(line1, e);
						count1 = count1 + numItems;
					}

					//lines 1 and 2 have an equal number of items, which is more than those in 3
					else if(count1 == count2 && count3 < count1)
					{
						enqueue(line3, e);
						count3 = count3 + numItems;
					}
		
					//lines 1 and 2 have an equal number of items, which is less than those in 3
					else if(count1 == count2 && count1 < count3)
					{
						enqueue(line1, e);
						count1 = count1 + numItems;
					}
	
					//lines 1 and 3 have an equal number of items, which is less than those in 2
					else if(count1 == count3 && count1 < count2)
					{
						enqueue(line1, e);
						count1 = count1 + numItems;
					}
					
					//lines 1 and 3 have an equal number of items, which is more than those in 2
					else if(count1 == count3 && count2 < count1)
					{
						enqueue(line2, e);
						count2 = count2 + numItems;
					}

					//line 1 has the least items
					else if(count1 < count2 && count1 < count3)
					{
						enqueue(line1, e);
						count1 = count1 + numItems;
					}

					//line 2 has the least items
					else if(count2 < count1 && count2 < count3)
					{
						enqueue(line2, e);
						count2 = count2 + numItems;
					}

					//line 3 has the least items
					else if(count3 < count2 && count3 < count1)
					{
						enqueue(line3, e);
						count3 = count3 + numItems;
					}
				}
			}

		}

		//after end of file is reached, continue to go through line and check ppl out
		if(isEmpty(line1) == 0 || isEmpty(line2) == 0 || isEmpty(line3) == 0)
		{
			Element *e;

			while(isEmpty(line1) == 0 || isEmpty(line2) == 0 || isEmpty(line3) == 0)
			{
				//if items still in line 1
				if(isEmpty(line1) == 0)
				{
					if(line1->head->element.numberOfItems != 0)
					{
						line1->head->element.numberOfItems--;
					}

					else
					{
						printf("Shopper %d finished checking out of line 1 at time %d\n", line1->head->element.shopperID, timer);
						dequeue(line1, e);
					}	
				}

				//if items still in line 2
				if(isEmpty(line2) == 0)
				{
					if(line2->head->element.numberOfItems != 0)
					{
						line2->head->element.numberOfItems--;
					}

					else
					{
						printf("Shopper %d finished checking out of line 2 at time %d\n", line2->head->element.shopperID, timer);
						dequeue(line2, e);
					}
				}

				//if items still in line 3
				if(isEmpty(line3) == 0)
				{
					if(line3->head->element.numberOfItems != 0)
					{
						line3->head->element.numberOfItems--;
					}

					else
					{
						printf("Shopper %d finished checking out of line 3 at time %d\n", line3->head->element.shopperID, timer);
						dequeue(line3, e);
					}
				}				

				timer++;

				//if all queues are empty, break
				if(isEmpty(line1) == 1 && isEmpty(line2) == 1 && isEmpty(line3) == 1)
				{
					break;
				}
			}
		}

		//free queues
		freeQueue(line1);
		freeQueue(line2);
		freeQueue(line3);

	}

    //close file
    fclose(fp);

    return 0;
}
