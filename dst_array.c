/*Array implementation of ist for operations:
	-insert data
	-remove it
	-count elements
	-Read/modify data at a particular position
	-specify datatype(list of int/float/string)
*/

#include <stdio.h>
#define MAX_SIZE 500

int arr[MAX_SIZE];
int end=-1;

int length()
{
	return end+1;
}

int show(int index)
{
	if(index>=0 && index<=end)
		return arr[index];
}

void modify(int index,int x)
{
	if(index>=0 && index<=end)
		arr[index]=x;
}

void insert_at_end(int x)
{
	if(end>= MAX_SIZE-1)
		return;

	arr[++end]=x;
}

void insert(int x,int index)
{
	if(end>= MAX_SIZE-1 || index<0)
		return;

	int i;
	for(i=end+1;i>index;i--)
	{
		arr[i]=arr[i-1];
	}
	arr[i]=x;
	end++;
}

void delete_from_end()
{
	if(end==-1)
		return;

	end--;
}

void delete(int index)
{
	if(index<0 || index>end)
		return;

	int i;
	for(i=index;i<end;i++)
	{
		arr[i]=arr[i+1];
	}
	end--;
}

int main()
{
	return 0;
}