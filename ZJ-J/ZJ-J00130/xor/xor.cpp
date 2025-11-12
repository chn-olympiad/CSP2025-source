#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int N=5e5+5;
int n,k,m,a[N],pr[N],f[N];
map<int,int> mp;
struct node{
	int l,r;
}b[N];
bool cmp(node q,node w){
	return q.r<w.r;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)  cin>>a[i];
	mp[k]=1;
	for(int i=1;i<=n;i++){
		pr[i]=a[i]^pr[i-1];
		if(mp.find(pr[i])!=mp.end()) b[++m].l=mp[pr[i]],b[m].r=i;
		mp[pr[i]^k]=i+1;
	}
	sort(b+1,b+m+1,cmp);
//	for(int i=1;i<=m;i++) cout<<b[i].l<<" "<<b[i].r<<"\n";
	int i=1,j=1;
	while(i<=n){
		if(i>b[j].l&&j<m) j++;
		else if(i==b[j].l) f[b[j].r]=max(f[b[j].r-1],f[b[j].l-1]+1),
						   f[i]=max(f[i],f[i-1]),i++,j++; 
		else f[i]=max(f[i],f[i-1]),i++;
//		cout<<i<<" "<<j<<" "<<f[i]<<"\n";
	}
	cout<<f[n];
	return 0;
}
