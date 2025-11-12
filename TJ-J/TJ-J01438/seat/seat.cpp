#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
struct student
{
	int score,index;
	bool operator<(const student& b)
	{
		return this->score<b.score;
	}
	bool operator>(const student& b)
	{
		return this->score>b.score;
	}
}students[100];
//#define DBG 1
int main()
{
	freopen("seat.in","r",stdin);
	#ifndef DBG
		freopen("seat.out","w",stdout);
	#endif
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		students[i].index=i;
		cin>>students[i].score;
	}
	int front_cnt=0;
	for(int i=1;i<n*m;i++)
	{
		if(students[i].score>students[0].score)
		{
			front_cnt++;
		}
	}
	int sorted_r=0,sorted_c=0;
	sorted_c=front_cnt/n+1;
	sorted_r=front_cnt%n;
	if(sorted_c%2==0)
	{
		sorted_r=n-sorted_r;
	}
	else
	{
		sorted_r++;
	}
	cout<<sorted_c<<' '<<sorted_r;
	return 0;
}
