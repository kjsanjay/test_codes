#Factorial 

# import math

while 1 :
	n=int(raw_input())

	list2=[]

	i=2
	# sq_rt=math.sqrt(n)

	while i*i <= n:
		while n%i ==0:
			list2.append(i)
			n/=i
		i+=1

	if n>1 :
		list2.append(n)

	print list2



