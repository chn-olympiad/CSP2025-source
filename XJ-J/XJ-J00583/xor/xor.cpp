#include <bits/stdc++.h>
using namespace std;
int n,k,a[500000+5],minn=2,maxn=0,ans;
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	if(k==0&&minn==maxn&&maxn==1){
		cout<<n/2;return 0;
	}
	int x=0,t;
	for(int i=1;i<=n;i++)
	{
		x=0;t=0;
		for(int j=i;j<=n;j++){
			x^=a[j];
			if(x==k){
				t=j;
				ans++;
				break;
			}
		}
		if(t!=0)i=t;
	}
	cout<<ans;
	return 0;
}
