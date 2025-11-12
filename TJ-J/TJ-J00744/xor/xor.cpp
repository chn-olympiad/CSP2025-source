#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+10;
int n,k,sum;
int a[MAXN];
bool vis[MAXN];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i]==k&&(vis[i-1]||a[i-1]==0))||(a[i-1]^a[i]==k&&!vis[i-1]))
		{
			sum++;
			vis[i]=1;
		}
		if(i>1)a[i]=a[i-1]^a[i];
	}
	cout<<sum;
	return 0;
}
