#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1005],x,ans;
//bool cmp(int a,int b)
//{
//	return a>b;
//}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>=a[1])	x++;
	}
//	ans=a[1];
//	sort(a+1,a+1+n*m,cmp);
//	for(int i=1;i<=n*m;i++)
//	{
//		if(a[i]==ans)
//		{
//			x=i;
//			break;
//		}
//	}
	if(x%(2*n)==0)
	{
		cout<<x/n<<" 1";
	}
	else{
		if(x%(2*n)>n)
		{
			if(x%n==0)
			{
				cout<<x/n<<" "<<2*n+1-x%(2*n);
			}
			else
				cout<<x/n+1<<" "<<2*n+1-x%(2*n);
		}
		else
		{
			if(x%n==0)	cout<<x/n<<" "<<x%(2*n);
			else	cout<<x/n+1<<" "<<x%(2*n);
		}
	}
	return 0;
}