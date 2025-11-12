#include<bits/stdc++.h>
#define endl '\n'
#define QwQ return 0;
#define IOSO ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
const int N=5e5+10;
int a[N],pre[N];
struct node{
	int l,r,len;
}g[N];
int tot=0;
int vis[N];
bool cmp(node x,node y){
	if(x.len!=y.len){
		return x.len<y.len;
	}else{
		if(x.l!=y.l){
			return x.l<y.l;
		}
		return x.r<y.r;
	}
}
int main(){
	IOSO
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=(pre[i-1]^a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int ans=pre[j]^pre[i-1];
			if(ans==k){
				g[++tot].l=i;
				g[tot].len=j-i+1;
				g[tot].r=j;
			}
		}
	}
	sort(g+1,g+1+tot,cmp);
	int cnt=0;
	for(int i=1;i<=tot;i++){
		bool flag=true;
		for(int j=g[i].l;j<=g[i].r;j++){
			if(vis[j]){
				flag=false;
				break;
			}
		}
		if(flag){
			cnt++;
			for(int j=g[i].l;j<=g[i].r;j++){
				vis[j]=1;
			}
		}
	}
	cout<<cnt<<endl;
	QwQ;
}
