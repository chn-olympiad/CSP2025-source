#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,a[N],mx;
void dfs(int l,int cut,int sum)
{
	mx%=998244353;
	if(cut>=2)
	{
		int k=lower_bound(a+l,a+n+1,sum)-a;
		mx+=k-l-1;
	}
	for(int i=l+1;i<n;i++) dfs(i,cut+1,sum+a[i]);
}

int main(){
	
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout << mx;
	
	return 0;
}