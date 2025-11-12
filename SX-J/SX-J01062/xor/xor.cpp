#include<bits/stdc++.h>

using namespace std;
int last[1<<24],n,m,ans,a[500005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	memset(last,-1,sizeof last);last[0]=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	int sum=0,emm=0;
	for(int i=1;i<=n;i++){
		sum^=a[i];
		if(last[sum^m]>=emm) ans++,emm=i;
		last[sum]=i;
	}
	cout<<ans;
	return 0;
}
