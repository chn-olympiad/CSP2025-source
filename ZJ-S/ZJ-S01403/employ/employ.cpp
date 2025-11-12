#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
const int TT=998244353;
int n,m,ans;
int c[maxn];
string s;
int read(){
	int tot=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')tot=tot*10+ch-'0',ch=getchar();
	return tot*f;
}
int a[maxn];
bool vis[maxn];
void dfs(int step){
	if(step>n){
		int now=0,cnt=0;
		for(int i=1;i<=n;i++)
		for(int j=0;j<n;j++){
			if(s[j]=='0')now++;
			else{
				if(now>=c[a[i]])now++;
				else now=0,cnt++;
			}
		}
		if(cnt>=m)ans=(ans+1)%TT;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		vis[i]=1;a[step]=i;
		dfs(step+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();m=read();
	cin>>s;
	for(int i=1;i<=n;i++)c[i]=read();
	dfs(1);
	printf("%d\n",ans);
	return 0;
}