#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int T,n;
struct node{
	int a1,a2,a3;
	int id;
}a[100010];
int ans; 
bool c2,c3;
bool cmp(node a,node b){
	return a.a1>b.a1;
}
void dfs(int t,int c1,int c2,int c3,int sum){
	if((c1>n/2)||(c2>n/2)||(c3>n/2))return ;
	if(t>n){
		ans=max(ans,sum);
		return ;
	}
	dfs(t+1,c1+1,c2,c3,sum+a[t].a1);
	dfs(t+1,c1,c2+1,c3,sum+a[t].a2);
	dfs(t+1,c1,c2,c3+1,sum+a[t].a3);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		ans=-99999;
		c2=0;
		c3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			a[i].id=i;
			if(a[i].a3!=0)c3=1;
			if(a[i].a2!=0)c2=1; 
		}
		if(c2==0&&c3==0){//A
			sort(a+1,a+n+1,cmp);
			ans=0;
			for(int i=1;i<=n/2;i++)ans+=a[i].a1;
			continue;
		}else{
			dfs(1,0,0,0,0);
		}
		cout<<ans<<endl;
	}
}

