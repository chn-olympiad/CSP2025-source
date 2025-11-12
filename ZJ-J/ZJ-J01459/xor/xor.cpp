#include<bits/stdc++.h>
using namespace std;
//freopen?
//long long?
//memset?
/*
10 pts
*/
int n;
int k,a[500010];
struct node{
	int tl,tr;
	int x;
}t[2000010];
bool check(){
	if(a[1]!=1)return false;
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1])return false;
	}
	return true;
}
void build(int i,int l,int r){
	if(l>r)return;
	t[i].tl=l;
	t[i].tr=r;
	if(l==r){
		t[i].x=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(2*i,l,mid);
	build(2*i+1,mid+1,r);
	t[i].x=t[2*i].x^t[2*i+1].x;
}
int ans(int i,int l,int r){
	if(l==r)return a[l];
	if(t[i].tr<l || t[i].tl>r)return -1;
	if(t[i].tl>=l && t[i].tr<=r)return t[i].x;
	int x1=ans(2*i,l,r),x2=ans(2*i+1,l,r);
	return x1==-1?x2:(x2==-1?x1:x1^x2);
}
int dfs(int l,int r){
	int cnt=-1;
	if(l>r)return 0;
	for(int i=l;i<r;i++){
		cnt=max(cnt,(max(ans(1,l,i)==k?1:0,dfs(l,i))+max(ans(1,i+1,r)==k?1:0,dfs(i+1,r))));
	}
	cnt=max(cnt,ans(1,l,r)==k?1:0);
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(check()){
		cout<<n/2<<endl;
		exit(0);
	}
	build(1,1,n);
	cout<<dfs(1,n)<<endl;
	return 0;
}