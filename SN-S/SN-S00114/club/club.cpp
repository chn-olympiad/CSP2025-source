//吴泊成 SN-S00114 西安市曲江第一中学 
#include<bits/stdc++.h>
using namespace std;
long long t,n,ans;
struct node{
	int a;
	int b;
	int c;
}a[200005];
void dfs(long long x,long long y,long long m,long long q,long long w,long long e){

	if(x==n+1){
		
		
		ans=max(ans,m);
		
		return;
	}
	
	dfs(x+1,1,m+a[x].a,q+1,w,e);
	dfs(x+1,2,m+a[x].b,q,w+1,e);	
	dfs(x+1,3,m+a[x].c,q,w,e+1);	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		dfs(1,1,0,0,0,0);
		dfs(1,2,0,0,0,0);
		dfs(1,3,0,0,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

