#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define L(i,l,r) for(int i(l);i<=(r);++i)
#define R(i,r,l) for(int i(r);i>=(l);--i)
using namespace std;
const int N=1e5+10,inf=0x7fffffff,mod=998244353; 
int genshin,n,a[N],b[N],c[N],t[4];
int cs(int x){
	int res=max({a[x],b[x],c[x]});
	if(res==a[x])return 1;
	if(res==b[x])return 2;
	return 3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>genshin;
	while(genshin--){
		t[1]=t[2]=t[3]=0;
		int res=0;
		cin>>n;
		L(i,1,n){
			cin>>a[i]>>b[i]>>c[i];
			res+=max({a[i],b[i],c[i]});
			++t[cs(i)];
		}
		if(max({t[1],t[2],t[3]})>n/2){
			int id=1;
			if(t[2]>t[id])id=2;
			if(t[3]>t[id])id=3;
			vector<int>vec;
			L(i,1,n)if(cs(i)==id){
				int tmp=-inf;
				if(id!=1)tmp=max(tmp,a[i]-max({a[i],b[i],c[i]}));
				if(id!=2)tmp=max(tmp,b[i]-max({a[i],b[i],c[i]}));
				if(id!=3)tmp=max(tmp,c[i]-max({a[i],b[i],c[i]}));
				vec.push_back(tmp);
			}
			sort(vec.begin(),vec.end());
			while(t[id]>n/2){
				res+=vec.back();
				vec.pop_back();
				--t[id];
			}
			cout<<res<<'\n';
		}
		else{
			cout<<res<<'\n';
		}
	}	
	return 0;
}
