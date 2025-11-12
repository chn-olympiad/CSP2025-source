#include <bits/stdc++.h>
using namespace std;
#define read(x) scanf("%d",&x)
const int N=1e5+10;
int t,tot[3],res[N],vis[N],ans,n;
struct node{
	int a,b,c;
	friend bool operator < (node x,node y){
		return x.a>y.a;
	}	
}name[N];
void dfs(int x,int cnt){
	if(x>n){
	/*	if(ans<cnt){
			for(int i=1;i<=n;i++)
				cout<<res[i]<<" ";
			cout<<"\n";
		}*/
		ans=max(ans,cnt);
		
		return;
	}
	if((tot[1]+1)*2<=n){
		tot[1]++;
	//	res[x]=1;
		dfs(x+1,cnt+name[x].a);
		tot[1]--;
	}if((tot[2]+1)*2<=n){
		tot[2]++;
	//	res[x]=2;
		dfs(x+1,cnt+name[x].b);
		tot[2]--;
	}if((tot[3]+1)*2<=n){
		tot[3]++;
	//	res[x]=3;
		dfs(x+1,cnt+name[x].c);
		tot[3]--;
	}
}
void solve(){
	read(n);ans=0;
	memset(tot,0,sizeof(tot));
	memset(name,0,sizeof(name));
	memset(vis,0,sizeof(vis));
//	memset(res,0,sizeof(res));
	for(int i=1;i<=n;i++){
		read(name[i].a);
		read(name[i].b);
		read(name[i].c);
	}
	if(n<=50)dfs(1,0);
	else if(n<=250){
		for(int i=1;i<=n/2;i++)
			ans+=name[i].a;
		for(int i=n/2+1;i<=n;i++)
			ans+=name[i].b;
		for(int i=n/2+1;i<=n;i++)
			for(int j=1;j<=n/2;j++)
				if(!vis[j]&&name[i].b+name[j].a<name[i].a+name[j].b)
					ans+=(name[i].a+name[j].b-name[j].a-name[i].b),vis[j]=1;			
	}else{
		sort(name+1,name+n+1);
		for(int i=1;i<=n/2;i++)
			ans+=name[i].a;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("club.in","r",stdin);
 	freopen("club.out","w",stdout);
	read(t);
	while(t--)solve();
	return 0;
}
