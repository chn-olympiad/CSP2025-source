#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],S[N],cnt,ans=-1;
struct edge{
	int l,r;
};
edge d[N];
vector<int> e[N];
int yh(int x,int y){
	int base=1,ans=0;
	while(x!=0||y!=0){
		if(x%2!=y%2) ans+=base;
		base*=2;
		x/=2,y/=2;
	}
	return ans;
}
void DFS(int now,int fa,int step){
	ans=max(ans,step);
	for(int v:e[now]){
		if(v==fa) continue;
		DFS(v,now,step+1);
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];S[i]=yh(S[i-1],a[i]);
	}
	for(int len=1;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			int j=i+len-1;
			if(yh(S[j],S[i-1])==k) d[++cnt]=(edge){i,j};
		}
	}
	for(int i=1;i<=cnt;i++){
		int ll=d[i].l,rr=d[i].r;
		for(int j=i+1;j<=cnt;j++){
			if(d[j].r<=d[i].l||d[j].l>=d[i].r) {
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	DFS(1,0,1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
