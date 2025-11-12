#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,ans,flag,tot[N];
struct node{
	int a,b,c;
}s[N];
inline int read(){
	int t=1,tot=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
inline int cmp(node a,node b){
	return a.a>b.a;
}
inline void dfs(int x,int sum,int s_1,int s_2,int s_3){
	if(sum+tot[n]-tot[x-1]<=ans) return;
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	if(s_1<(n>>1)) dfs(x+1,sum+s[x].a,s_1+1,s_2,s_3);
	if(s_2<(n>>1)) dfs(x+1,sum+s[x].b,s_1,s_2+1,s_3);
	if(s_3<(n>>1)) dfs(x+1,sum+s[x].c,s_1,s_2,s_3+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read(); ans=0;
		for(int i=1;i<=n;i++){
			s[i].a=read();
			s[i].b=read();
			s[i].c=read();
			if(s[i].c!=0) flag=2;
			else if(s[i].b!=0) flag=1;
			tot[i]=tot[i-1]+max(s[i].a,max(s[i].b,s[i].c));
		}
		if(flag==0){
			sort(s+1,s+n+1,cmp);
			for(int i=1;i<=(n>>1);i++) ans+=s[i].a;
			cout<<ans<<endl;
			continue;
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}
