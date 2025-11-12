#include<bits/stdc++.h>
using namespace std;
int a[110],sum;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)
		{
			sum=a[i];
		}
	}
	int z=m*n;
	sort(a+1,a+z+1,greater<int>());
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==sum)
		{
			if(i%n!=0)
			{
				cout<<i/n+1;
			}
			else{
				cout<<i/n;
			}
			cout<<" ";
			if(((i/n)+1)%2==1)
			{
				cout<<i%n;
			}
			else{
				cout<<(i%n)+(n-(i%n));
			}
			return 0;
		}
	}
	return 0;
}
