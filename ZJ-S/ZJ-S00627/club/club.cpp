#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T,n,a[maxn][3],val[maxn];
inline int read(){
	int ret=0,f=1;
	char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-f;c=getchar();}
	while(isdigit(c)){ret=ret*10+c-'0';c=getchar();}
	return ret*f;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i][0]=read(),a[i][1]=read(),a[i][2]=read();
		vector<int> cho[3];int ans=0;
		for(int i=1;i<=n;i++){
			int now=max({a[i][0],a[i][1],a[i][2]});
			if(now==a[i][0])cho[0].push_back(i);
			else if(now==a[i][1])cho[1].push_back(i);
			else cho[2].push_back(i);
			ans+=now;
		}
		int pos=-1;
		if(cho[0].size()>n/2)pos=0;
		if(cho[1].size()>n/2)pos=1;
		if(cho[2].size()>n/2)pos=2;
		if(pos==-1){printf("%d\n",ans);continue;}
		int tot=0;
		for(auto i:cho[pos]){
			int ano;
			if(pos==0)ano=max(a[i][1],a[i][2]);
			if(pos==1)ano=max(a[i][0],a[i][2]);
			if(pos==2)ano=max(a[i][0],a[i][1]);
			val[++tot]=ano-max({a[i][0],a[i][1],a[i][2]});
		}
		sort(val+1,val+tot+1,greater<int>());
		for(int i=1;i<=tot-n/2;i++)ans+=val[i];
		printf("%d\n",ans);
	}
	return 0;
}
