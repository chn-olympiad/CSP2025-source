#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N],s[N],b[5000005],n,m,len;
struct node{
	int l,r;
}w[N];
bool cmp(node x,node y){
	return x.r<y.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	memset(b,-1,sizeof(b));
	b[0]=0;
	for (int i=1;i<=n;i++){
		int o=s[i]^m;
		if (b[o]!=-1){
			w[++len].l=b[o]+1;
			w[len].r=i;
		}
		b[s[i]]=i;
	}
	sort(w+1,w+1+len,cmp);
	int ans=0,r=0;
	for (int i=1;i<=len;i++){
		if (w[i].l>r){
			ans++;
			r=w[i].r;
		}
	}
	cout<<ans;
	return 0;
}
/*
4 3
2 1 0 3
*/