#include<bits/stdc++.h>
#define int long long
#define cen cout << "\n"
#define c1 cout << "1 "
using namespace std;
struct node{
	int a,b,val;
};
vector<node> son;
int c[19];
int ar[19][10009];
int fa[10099];
int ffa(int x){
	if(fa[x]==x){
		return x;
	}
	else{
		fa[x]=ffa(fa[x]);
		return fa[x];
	}
}
int u(int a,int b){
	fa[ffa(a)]=ffa(b);
}
int temp[10009];
bool cmp(node a,node b){
	return a.val<b.val;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		son.push_back({a,b,c});
	}
	int flag=1;
	for(int i=1;i<=k;i++){
		cin >> c[i];
		if(c[i]!=0){
			flag=0;
		}
		for(int j=1;j<=n;j++){
			cin >> ar[i][j];
		}
	}
	if(flag){
		int res=0;
		for(int i=0;i<=n+k+1;i++){
			fa[i]=i;
		}		

		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				son.push_back({j,n+i,ar[i][j]});
				if(ar[i][j]==0){
					u(n+i,j);
				}
			}
		}
		
		sort(son.begin(),son.end(),cmp);		
		for(int i=0;i<son.size();i++){
			int a=son[i].a,b=son[i].b,val=son[i].val;
			if(ffa(a)!=ffa(b)){
				
				res+=val;
				u(a,b);
			}
		}
	
		cout << res;
		return 0;
	}
	int res=4e18;
	for(int kk=0;kk<(2<<k);kk++){
		int ans=0;
		for(int i=1;i<=k;i++){
			if((2<<i)&kk){
				ans+=c[i];
				for(int j=1;j<=n;j++){
					son.push_back({j,n+i,ar[i][j]});
				}
			}
		}
		for(int i=1;i<=n+k;i++){
			fa[i]=i;
		}
		sort(son.begin(),son.end(),cmp);
		for(int i=0;i<son.size();i++){
			int a=son[i].a,b=son[i].b,val=son[i].val;
			if(ffa(a)!=ffa(b)){
				ans+=val;
				u(a,b);
			}
		}
		res=min(res,ans);
	}
	cout << res;
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
