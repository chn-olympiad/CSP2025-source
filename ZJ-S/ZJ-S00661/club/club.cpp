#include<bits/stdc++.h>
using namespace std;
int s[100010][3];
int mxh[100010];
int n;
int ans=0;
int d=0;
void dfs(int x,int now,int a,int b,int c){
	if(a>n/2||b>n/2||c>n/2)return;
	if(x>n){
		ans=max(ans,now);
		d=1;
		return;
	}
	if(now+mxh[x]<=ans)return;
//	cout<<now<<' '<<a<<' '<<b<<' '<<c<<'\n';
	dfs(x+1,now+s[x][0],a+1,b,c);
	dfs(x+1,now+s[x][1],a,b+1,c);
	dfs(x+1,now+s[x][2],a,b,c+1);
	return;
}
int caa[100010];
int cca[100010][2];
struct ccca{
	int c,id;
	bool operator <(const ccca &x)const{
		return c<x.c;
	}
}cccca[100010];
void solve(){
	scanf("%d",&n);
	bool ddd=true;
	for(int i=1;i<=n;i++){
		mxh[i]=caa[i]=cca[i][0]=cca[i][1]=cccca[i].c=cccca[i].id=0;
		scanf("%d%d%d",&s[i][0],&s[i][1],&s[i][2]);
		if(s[i][2]>s[i][0]||s[i][2]>s[i][1]){
			ddd=false;
		}
	}
	mxh[n+1]=0;
	for(int i=n;i>=1;i--){
		int mx=max({s[i][0],s[i][1],s[i][2]});
		mxh[i]=mxh[i+1]+mx;
	}
	if(n<=30){
		ans=0;
		dfs(1,0,0,0,0);
		printf("%d\n",ans);
		return;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		ans+=s[i][0];
		cca[i][0]=s[i][1]-s[i][0];
		cca[i][1]=s[i][2]-s[i][0];
		cccca[i].c=s[i][2]-s[i][1];
		cccca[i].id=i;
	}
	if(ddd){
		for(int i=1;i<=n;i++){
			caa[i]=s[i][1]-s[i][0];
		}
		sort(caa+1,caa+n+1);
		for(int i=n;i>n/2;i--){
			ans+=caa[i];
		}
		printf("%d\n",ans);
		return;
	}
	sort(cccca+1,cccca+n+1);
	for(int i=n;i>n/2;i--){
		cccca[i].c=cca[cccca[i].id][1];
	}
	for(int i=n/2;i>=1;i--){
		cccca[i].c=cca[cccca[i].id][0];
	}
	sort(cccca+1,cccca+n+1);
	for(int i=n;i>n/2;i--){
		ans+=cccca[i].c;
	}
	for(int i=n/2;i>0&&cccca[i].c>=0;i--){
		ans+=cccca[i].c;
	}
	printf("%d\n",ans);
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
