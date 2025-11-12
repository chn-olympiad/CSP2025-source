#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int n,res,ct,a[N][3],b[N],c[3],w[N];
void sol()
{
	cin>>n,res=ct=0;
	for(int i=0;i<3;i++) c[i]=0;
	for(int i=1;i<=n;i++)
	{
		b[i]=0;
		for(int j=0;j<3;j++)
		{
			cin>>a[i][j];
			if(a[i][j]>a[i][b[i]]) b[i]=j;
		}
		c[b[i]]++,res+=a[i][b[i]];
	}
	for(int j=0;j<3;j++) if(c[j]>n/2)
	{
		for(int i=1;i<=n;i++) if(b[i]==j) w[++ct]=a[i][j]-max(a[i][(j+1)%3],a[i][(j+2)%3]);
		sort(w+1,w+1+ct);
		for(int i=1;i<=c[j]-n/2;i++) res-=w[i];
	}
	cout<<res<<'\n';
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int TT; cin>>TT;
	while(TT--) sol();
	return 0;
}
