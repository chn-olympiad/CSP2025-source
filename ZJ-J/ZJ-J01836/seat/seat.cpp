#include<bits/stdc++.h>
using namespace std;
int a[1000];
int sum=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
	    cin>>a[i];
		
			
			if(a[1]<a[i])
			sum++;
	}
	if((sum+1)%n==0&&(sum+1)/n%2==0)
	cout<<(sum+1)/n<<" "<<1;
	else
	if((sum+1)%n==0&&(sum+1)/n%2!=0)
	cout<<(sum+1)/n<<" "<<n;
	else
	if((sum+1)%n!=0&&(sum+1)/n%2!=0)
	cout<<(sum+1)/n+1<<" "<<(sum+1)/n*n;
	else
	if((sum+1)%n!=0&&(sum+1)/n%2==0)
	cout<<(sum+1)/n+1<<" "<<n-(sum+1)/n*n;
	fclose(stdin);
	fclose(stdout);
}