#include <bits/stdc++.h>
using namespace std;
int t,n,k=0;
struct ab{
	int a,b,c;
}a[100005];
void dfs(int x,int zs,int aa,int bb,int cc){
	if(x==n){
		k=max(k,zs);
	}else{
		if(aa<(n/2)){
			dfs(x+1,zs+a[x+1].a,aa+1,bb,cc);
		}
		if(bb<(n/2)){
			dfs(x+1,zs+a[x+1].b,aa,bb+1,cc);
		}
		if(cc<(n/2)){
			dfs(x+1,zs+a[x+1].c,aa,bb,cc+1);
		}
	}
}
int main(){
	freopen("club.in","r",stdin); 
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		k=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		dfs(0,0,0,0,0);
		cout<<k<<endl;
	}
	
	return 0;
}
//中华人民共和国万岁 
