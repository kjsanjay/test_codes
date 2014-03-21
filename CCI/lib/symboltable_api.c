/*

Symbol Table API

*/

int contains(int key)
{
	return get(key) !=NULL;


}


void delete(int key)
{

	put(key,0);
}