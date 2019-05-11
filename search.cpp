#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <cassert>

template <typename T>
int LinearSearch( std::vector<T> list, T element)
{
	for(int i = 0;  i < list.size(); i++)
	{
		if( element == list[i])
			return i;
	}
	return -1; 
}

template <typename T>
int BinarySearch(std::vector<T> list, T element)
{
	int low = 0;
	int high = list.size();
	bool found =true;
	while(low<high )
	{
		int mid = (low+high)/2;
		
		if(list[mid]==element)
			return mid;
		
		else if (element<list[mid])
			high=mid-1;
				
		else if(element>list[mid])
			low=mid+1;
		
		else
			break;
	}

	return -1;
}


int recursiveBinarySearch(int* sortedArr, int low , int high, int element)
{

	if(low<=high)
	{
		int mid = (low+high)/2;
	
		if(sortedArr[mid]==element)
			return mid;
		
		else if (element<sortedArr[mid])
			return recursiveBinarySearch(sortedArr, low, mid-1, element);
				
		else if(element>sortedArr[mid])
			return recursiveBinarySearch(sortedArr, mid+1, high, element);
	}	
	return -1;
}



void Merge(int* list, int low, int x, int high)
{
	assert(low <= x);
	assert(x <= high);

	int cursor1=low;
	int cursor2=x+1;
	int counter=low;
	int temp[]={0,0,0,0,0,0,0,0};
	
	while( (cursor1<=x) && (cursor2<=high) )
	{
		if(list[cursor1]<=list[cursor2])
		{
			
			temp[counter]=list[cursor1]; 
			cursor1= cursor1+1; 
		}
		else
		{
			temp[counter]=list[cursor2];
			cursor2= cursor2+1;
		}
		counter = counter+1;
	}

	if(cursor1>x)
	{
		for(int i=cursor2; i<=high; i++)
		{
			temp[counter]=list[i];
			counter=counter+1;
		}
	}

	else
	{
		for(int i=cursor1; i<=x; i++)
		{
			temp[counter]=list[i];
			counter=counter+1;
		}
	}
	
	
	for(int i=low; i<=high; i++)
	{
		list[i]=temp[i];
	}
}

void MergeSort(int* list1, int low, int high)
{	
	
	if(low<high)	
	{	
		int mid=(low+high)/2;	
		MergeSort(list1, low, mid);
		MergeSort(list1, mid+1, high);
		Merge(list1, low, mid, high);
	}
}


int Partition(int* list, int low, int high, int position)
{	
	int moveright=low;
	int moveleft=high+1;
	int x=list[low];

	while(moveright<moveleft)
	{
		do
		{
			moveright+=1;
		}
        while((list[moveright]<=x));
		
		do
		{
			moveleft-=1;
		}
        while((list[moveleft]>=x));
	
		if(moveright<moveleft)
		{
			int a=list[moveright];
			list[moveright]=list[moveleft];
			list[moveleft]=a;
		}
	}
	
	position=moveleft;
	list[low]=list[position];
	list[position]=x;
	return position;
}

void QuickSort(int* list, int low, int high)
{	
	if(low<high)
	{
		int position;
		position=Partition(list, low, high, position);
		QuickSort(list, low, position -1);
		QuickSort(list, position+1, high);
	}
}


int Factorial(int element)
{
	if(element>=2)
		element= element*Factorial(element-1);
	else if(element==0)
		element=1;
	return element;
}

void Fibonacci(std::vector<int>& vector, int n)
{	
	if(0==n)
	{
		vector.push_back(0);
	}
	else	if(1==n)
	{
		Fibonacci( vector, n -1);
		vector.push_back(1);
	}
	else if(2==n)
	{
		Fibonacci( vector, n -1);
		vector.push_back(1);
	}
	else if(n>2)
	{
		Fibonacci( vector, n-1);
		int a=vector[n-2]+vector[n-1];
		vector.push_back(a);		
	}
}

void rec(std::vector<int>& vector, int n)
{	
	if(0==n)
	{
		vector.push_back(5);
	}
	else	if(1==n)
	{
		rec( vector, n-1);
		vector.push_back(10);
	}
	else if(2==n)
	{
		rec( vector, n-1);
		vector.push_back(11);
	}
	else if(n>2)
	{
		rec( vector, n-1);
		int a=vector[n-2]*3;
		vector.push_back(a);		
	}
}

int main()
{
	 //const char name[10] = {'B', 'e', 'r', 'n', 'a', '\0'};
	
	//std::cout << strnlen(name, 10);
	std::vector<int> list = {1,8,3,7,5,6,2,4};
	int list1[] = {1,8,3,7};
	std::vector<std::string> slist ={"1a","2a","3a","4a","5a","6a","7a","8a"}; 
/*
	std::cout << LinearSearch(list, 3) << std::endl;
	std::string a="3a";
	std::cout << LinearSearch(slist, std::string("6a")) << std::endl;
	std::cout << BinarySearch(list, 9) << std::endl; */

	//MergeSort(list1, 0,7);
	QuickSort( list1, 0, 3);
	//std::cout << "Found:" << recursiveBinarySearch(list1,0,3,3)<< std::endl;
	for(int i=0; i<4; i++)
	{
		//std::cout<<list1[i]<<"  " <<std::endl;
	}
	std::cout<<"Factorial:"<<Factorial(5)<<std::endl;

	std::vector<int> fibo;
	//Fibonacci(fibo, 9);
	rec(fibo,4);
	for(auto i : fibo)
	{
		std::cout<<i<<"  " <<std::endl;
	}
return 0;
}
