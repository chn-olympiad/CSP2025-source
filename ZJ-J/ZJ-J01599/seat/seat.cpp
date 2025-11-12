#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1001;
int n,m;
int a[N];
bool cmp(int a,int b){return a>b;}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i) cin>>a[i];
	int k=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;++i)
		if(k==a[i]){k=i;break;}
	if(!(k%n))
	{
		cout<<k/n<<" ";
		if((k/n)%2==0) cout<<1;
		else cout<<n;
	}
	else 
	{
		cout<<k/n+1<<" ";
		if((k/n)%2==0) cout<<k%n;
		else cout<<n-k%n+1;
	}
}
