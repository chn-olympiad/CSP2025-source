#include<bits/stdc++.h>
#define int long long
using namespace std;
struct lr{
	int l,r;
}s[40003000];
int f[500500];
int n,k,p;
int rs;
bool cmp(lr x,lr y){
	return x.r<y.r;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int a;cin>>a;f[i]=f[i-1]^a;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((f[j]^f[i-1])==k){
				p++,s[p].l=i,s[p].r=j;
			}
		}
	}
	sort(s+1,s+p+1,cmp);
	int ss=0;rs=s[1].r;
	for(int i=1;i<=p;i++){
		if(s[i].l>=rs)ss++,rs=s[i].r+1;
	}
	cout<<ss<<"\n";
	return 0;
}
//错因:[l,r]中可能有更多(=k)的区间
