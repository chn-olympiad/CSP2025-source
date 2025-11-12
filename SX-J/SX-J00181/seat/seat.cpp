#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l=n*m,r=0,arr=0,brr=1;
	for(int i=1;i<=l;i++) cin>>a[i];
	int sum=a[1];
	sort(a+1,a+l+1);
	for(int i=l;i>=1;i--) b[++r]=a[i];
	for(int i=1;i<=r;i++)
	{
		if(b[i]==sum)
		{
			arr=i;
			break;
		}
	}
	if(arr<=n)
	{
		cout<<1<<" "<<arr;
		return 0;
	}
	while(arr>n)
	{
		arr-=n;
		brr++;
	}
	cout<<brr<<" ";
	if(brr%2==0)
	{
		if(n-arr==1) cout<<n;
		else if(n-arr==0) cout<<1;
		else cout<<n-arr;
	}
	else
	{
		cout<<arr;
	}
	return 0;
}
