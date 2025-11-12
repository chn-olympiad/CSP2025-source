#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Dor(i,x,y) for(int i=x;i>=y;i--)
#define ll long long
using namespace std;
const int N=1e5+5;
int t,n,tmp,tot[5];
ll ans;
struct node{
	int x,y,z;
}a[N];
int read(){
	int f=1,s=0;
	char c=getchar();
	while(c>'9' || '0'>c){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9') s=s*10+c-'0',c=getchar();
	return s*f;
}
int check(int x,int y){
	if(y==1) return a[x].x;
	else if(y==2) return a[x].y;
	return a[x].z;
}
void dfs(int now,ll sum){
	if(tot[1]>tmp || tot[2]>tmp || tot[3]>tmp) 
		return ;
	if(now>n){
		ans=max(ans,sum);
		return ;
	}
	For(i,1,3){
		tot[i]++;
		dfs(now+1,sum+check(now,i));
		tot[i]--;
	}	
}
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	t=read();
	while(t--){
		n=read();
		tmp=n/2;
		int f=0;
		For(i,1,n){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			if(a[i].y!=0 || a[i].z!=0) f=1;
		}
		memset(tot,0,sizeof(tot));
		ans=0;
		if(f==0){
			sort(a+1,a+n+1,cmp);
			For(i,1,tmp) ans+=a[i].x;
			cout<<ans<<'\n';
			continue;
		}
		dfs(1,0);
		cout<<ans<<'\n';
	}
	return 0;
}
