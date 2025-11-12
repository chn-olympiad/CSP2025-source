#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],maxn=0,len=0;
bool flag=1;
bool check(int l,int r){
	int x=a[l];
	for(int i=l+1;i<=r;i++) x=x^a[i];
	if(x==k) return 1;
	else return 0;
}
struct node{
	int l,r;
};
vector<node> v;
bool cmp(node x,node y){
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
void dfs(int x,int y,int last_r){
	maxn=max(maxn,y);
	if(x>=len) return ;
	dfs(x+1,y,last_r);
	if(v[x].l>last_r) dfs(x+1,y+1,v[x].r);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) flag=0;
	}
	//全为0或1 
	if(flag){
		for(int i=1;i<=n;i++){
			if(a[i]==k) maxn++;
		}
		cout<<maxn;
		return 0;
	}
	
	//标记出所有符合要求区间 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j)) v.push_back({i,j});
		}
	}
	len=v.size();
	sort(v.begin(),v.end(),cmp);
	//范围小就爆搜 
	if(len<=30){
		dfs(0,0,0);
		cout<<maxn;
		return 0;
	}
	//范围大就贪心（我不确定正确性。看上去似乎是错的 
	int last_r=0;
	for(int i=0;i<len;i++){
		if(last_r>=v[i].l) continue;
		last_r=v[i].r;
		maxn++;
	}
	cout<<maxn;
	return 0;
}
//45分 
