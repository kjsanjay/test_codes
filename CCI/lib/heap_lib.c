/*


Heap library

-> Priority Queue implemented using binary heap
*/


int N;		//Stores size of heap
int *pq;



static int less(int a,int b);
static void exch(int a,int b);


void createpq(int capacity)
{
	pq=calloc(capacity,1);


}


int isEmpty()
{	
	return N==0;


}

//Child becomes larger than parent
void swim(int k)
{

	//Check child-(k) & parent-(k/2)
	while(k>0 && pq[k/2]<pq[k])
	{
		//swap child & parent
		exch(k/2,k);

		//Check for each parent
		k=k/2;

	}



} 

void insert(int data)
{
	//Insert at the end
	pq[++N]=data;

	//Check for child-parent ordering issues
	swim(N);


}

//If parent is demoted
void sink(int k)
{
	while(2*k <= N)
	{
		int j=2*k;
		
		//Check while of the children is greater
		//Childern of node -k 
		//(2k)=> Left (2k+1)=>Right
		//Higher child
		if(j<N && less(j,j+1))
			j++;

		//if higher child is less than parent
		//Then heap is in order-break
		if(!less(k,j))
			break;

		//Exchange the higher child & parent. repeat
		exch(k,j);

		k=j;
	}
}

int delMax()
{
	//delete the key
	//Decrement N
	int max=pq[0];
	//Put highest key in the end
	exch(0,N--);
	//check consistency
	sink(1);
	pq[N+1]=0;
	return max;


}

static int less(int a,int b)
{
	if(pq[a]<pq[b])
		return 1;
	else
		return 0;
}


static void exch(int a,int b)
{
	int tmp;
	tmp=pq[a];
	pq[a]=pq[b];
	pq[b]=tmp;


}