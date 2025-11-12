#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,pre[N],a[N],t;
stack<int>st[N];
struct node{
	int l,r;
}lr[N];
bool cmp(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//=================
	cin>>n>>k;
	st[0].push(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]^pre[i-1];
		st[pre[i]].push(i);
	}
	for(int i=n;i>=1;i--){
		int ans=k^pre[i];
		if(st[ans].empty())continue;
		while(!st[ans].empty()&&st[ans].top()>=i)st[ans].pop();
		if(st[ans].empty())continue;
		lr[++t].l=st[ans].top()+1;
		lr[t].r=i;
	}
	sort(lr+1,lr+t+1,cmp);
	int last=0,ans=0;
	for(int i=1;i<=t;i++){
		if(lr[i].l>last){
			ans++;
			last=lr[i].r;
		}
	}
	cout<<ans;
	//=================
	fclose(stdin);
	fclose(stdout);
	return 0;
}
