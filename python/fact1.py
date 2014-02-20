#Factorial 

import math

while 1 :
	n=int(raw_input())

	list2=[]

	while n%2==0 :
		list2.append(2);
		n=n/2

	i=3
	sq_rt=math.sqrt(n)

	while i <= sq_rt :
		while n%i==0 :
			list2.append(i)
			n=n/i

		i=i+2


	if(n>2) :
		list2.append(n)


	print list2



