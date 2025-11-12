#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005,MAXX=2000005;
int n,k,a,sum[MAXN],p[MAXX],pos,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	pos=0;
	memset(p,-1,sizeof(p));
	p[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum[i]=sum[i-1]^a;
		if(p[sum[i]^k]>=pos){
			ans++;
			pos=i;
		}
		p[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}
