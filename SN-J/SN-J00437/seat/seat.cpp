#include<bits/stdc++.h>
#define ll long long
#define PII pair<int,int>
using namespace std;

const int N=1e5+10;

int n,m,a[N],tt,x;

bool cmp(int a,int b) {return a>b;}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m>>x; a[++tt]=x;
	for (int i=2;i<=n*m;i++) cin>>a[++tt];
	
	sort(a+1,a+tt+1,cmp);
	
	int nx=1,ny=1;
	for (int i=1;i<=tt;i++)
	{
		if (a[i]==x) 
		{
			cout<<ny<<" "<<nx;
			return 0;
		}
		if (ny%2==1)
		{
			if (nx!=n) nx++;
			else ny++;
		}
		else
		{
			if (nx!=1) nx--;
			else ny++;
		}
	}
	
 	return 0;
}

