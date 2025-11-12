#include<bits/stdc++.h>
using namespace std;
long long n,a[5010],ans;
void dfs(int l,int k,int maxx,int sum)
{
//	cout<<l<<" "<<k<<" "<<maxx<<" "<<sum<<" "<<endl<<"{"<<endl;
	if(l==n)
	{
		if(k>=3&&sum>maxx*2)
		{
//			cout<<sum<<' '<<maxx<<endl;
			ans++;
			ans%=998244353;
		}
		return;
	}
	dfs(l+1,k+1,a[l+1],sum+a[l+1]);
	dfs(l+1,k,maxx,sum);
//	cout<<"}\n";
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	dfs(0,0,0,0);
	cout<<ans;
	return 0;
}


