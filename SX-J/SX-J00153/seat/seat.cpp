#include<bits/stdc++.h>
using namespace std;
int n,m,arr[10086];
//struct node
//{
//	int cj,id;
//}arr[10086];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)	cin>>arr[i];
	int lk=arr[1];
	sort(arr+1,arr+n*m+1,cmp);
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(arr[i*n+j]==lk)
			{
				if((i+1)%2==1)	cout<<i+1<<' '<<j;
				else			cout<<i+1<<' '<<n-j+1;
				return 0;
			}
		}
	}
	return 0;
}
/*
2 3
94 95 96 97 98 99

99 96 95
98 97 94

3 2




*/