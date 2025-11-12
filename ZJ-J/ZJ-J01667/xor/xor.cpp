#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
int c[500005],q[500005];
int cnt;
struct s{
	int l,r;
}d[500005];
bool cmp(s a,s b){
	return a.r<b.r;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		q[i]=q[i-1]^c[i];
	}
	for(int i=1;i<=n;i++){
		mp[q[i]]=i;
		int L=i-1;
		if(mp[q[L]^k]!=0){
			int j=mp[q[L]^k];
			if(i>j)continue;
			d[++cnt].l=i;
			d[cnt].r=j;
		}
	}
	sort(d+1,d+cnt+1,cmp);
	int ans=1;
	int backkk=d[1].r;
	for(int i=2;i<=cnt;i++){
		if(d[i].l>backkk){
			ans++;
			backkk=d[i].r;
		}
	}
	cout<<ans;
	return 0;
}