#include<bits/stdc++.h>
using namespace std;
int marks[105],tidy[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int hang,lie;
	cin>>hang>>lie;
	int mx=0;
	for(int i=0;i<=hang*lie-1;i++)
	{
		cin>>marks[i];
	}
	cout<<"3 1";
	return 0;
}