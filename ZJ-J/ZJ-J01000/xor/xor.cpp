#include<bits/stdc++.h>
using namespace std;
int tr[10000009][2],idx=1;
int st[500009];
int fun(int a){
	int u=0;
	for(int i=0;i<20;i++){
		int e=a>>i&1;
		if(tr[u][e])u=tr[u][e];
		else return 0;
	}
	return st[u];
}
void insert(int a,int b){
	int u=0;
	for(int i=0;i<20;i++){
		int e=a>>i&1;
		if(tr[u][e])u=tr[u][e];
		else {
			u=tr[u][e]=idx++;
		}
	}
	st[u]=b;
}
struct obj{
	int l,r;
} g[500009];
int cnt;
bool cmp(obj a,obj b){
	if(a.r<b.r)return 1;
	return 0;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int sum=0;
	insert(0,1);
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		sum^=a;
		int x=sum^k;
		int l=fun(x);
		if(l)g[++cnt]={l,i};
		insert(sum,i+1);
	}
	sort(g+1,g+1+cnt,cmp);
	int x=0;
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(g[i].l>x){
			ans++;
			x=g[i].r;
		}
	}
	cout<<ans;
	return 0;
}
