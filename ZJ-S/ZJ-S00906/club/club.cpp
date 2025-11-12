#include<bits/stdc++.h>
using namespace std;
int ans=-1;
int a,b,c;
int n;
struct node{
	int x,y,z;
};
node aa[2000];
void dfs(int k,int h){
	if(k==n+1){
		ans=max(ans,h);
		return;
	}
	if(a<n/2){
		a++;
		dfs(k+1,h+aa[k].x);
		a--;
	}
	if(b<n/2){
		b++;
		dfs(k+1,h+aa[k].y);
		b--;
	}
	if(c<n/2){
		c++;
		dfs(k+1,h+aa[k].z);
		c--;
	}
}
int main(){
	int t;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=-1;
		a=0,b=0,c=0;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>aa[i].x>>aa[i].y>>aa[i].z;
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}