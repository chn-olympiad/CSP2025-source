#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
const int maxn=1e5+5;
int read(){
	int f=1,x=0;
	char ch=getchar();
	while (ch<'0' || '9'<ch){
		if (ch=='-') f*=-1;
		ch=getchar();
	}
	while ('0'<=ch && ch<='9'){
		x=(x*10+ch-'0');
		ch=getchar();
	}
	return f*x;
}
int T,n,ans;
int s[maxn][4];
int vec[maxn];
void dfs(int cur,int ck,int a,int b,int c,int res){
	if (ck==1) a++;
	if (ck==2) b++;
	if (ck==3) c++;
	if (a>n/2 || b>n/2 || c>n/2) return;
	if (cur==n){
		ans=max(ans,res);
		return;
	}
	dfs(cur+1,1,a,b,c,res+s[cur+1][1]);
	dfs(cur+1,2,a,b,c,res+s[cur+1][2]);
	dfs(cur+1,3,a,b,c,res+s[cur+1][3]);
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while (T--){
		bool flag=true;
		ans=0;
		n=read();
		for (int i=1;i<=n;i++){
			s[i][1]=read();
			s[i][2]=read();
			s[i][3]=read();
			if (s[i][2]!=0 || s[i][3]!=0)
				flag=false;
		}
		if (flag){
			for (int i=1;i<=n;i++)
				vec[i]=s[i][1];
			sort(vec+1,vec+1+n,cmp);
			for (int i=1;i<=n/2;i++)
				ans+=vec[i];
			cout<<ans<<'\n';
			continue;
		}
		dfs(0,0,0,0,0,0);
		cout<<ans<<'\n';
	}
	return 0;
}
//freopen("")
//uid:1335720 @TC_QD
//wan quan bu hui QAQ
//[61,81]pts?
//AFO.
