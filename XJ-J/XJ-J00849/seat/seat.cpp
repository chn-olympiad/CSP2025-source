#include<bits/stdc++.h>
using namespace std;
int arr[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		cin>>arr[i];
	}
	int madex=arr[0];
	sort(arr,arr+n*m);
	int findx=0,ci=0;
	for(int i=n*m-1;i>=0;i--)
	{
		ci++;
		if(arr[i]==madex)
		{
			findx=ci;
			break;
		}
	 } 
	if(findx%n==0)
	{
		cout<<findx/n<<" ";
		if(findx<=n)
	 	{
	 		cout<<findx;
	 	}
		else
		{
	 		if((findx/n)%2!=0)
	 		{
	 			cout<<findx%n;
			}
			else
			{
				cout<<n-findx%n+1;
			}
	 		
	 	}
	}
	else
	{
		cout<<findx/n+1<<" ";
		if(findx<=n)
	 	{
	 		cout<<findx;
	 	}
		else
		{
	 		if((findx/n+1)%2!=0)
	 		{
	 			cout<<findx%n;
			}
			else
			{
				cout<<n-findx%n+1;
			}
	 		
	 	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
