#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[105];

bool cmp(int x,int y)
{
	return x>y;
} 

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int a=1;a<=n*m;a++)
		cin>>arr[a];
	int n=arr[1];
	int xb=0;
	sort(arr,arr+n*m,cmp);
	for(int a=1;a<=n*m;a++)
	{
		if(arr[a]==n)
		{
			xb=a;
			break;
		}
	}
	int x=xb+n-1;
	x/=n;
	int y=x-1;
	xb-=y*n;
	if(x%2==0)
		y=n+1-xb;
	else
		y=xb;
	cout<<x<<" "<<y;
		
	
	
	return 0;
} 
