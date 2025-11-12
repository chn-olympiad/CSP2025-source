#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,r;
int k[10005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++) 
	{
		cin>>k[i];
		if(m*n==1&&m==n)
		{
			cout<<"1"<<" "<<"1";
			return 0;
		}
	}
	r=k[0];
	sort(k,k+1);
	for(int i=1;i<=m*n;i++)
	{
		if(k[i]==r){
			if(m>n)
			cout<<"1"<<" "<<i;
			else if(m<n)
			cout<<i<<" "<<"1";
		}
	}
	return 0;
}
