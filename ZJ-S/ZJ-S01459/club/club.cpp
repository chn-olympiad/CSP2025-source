#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){//mention int/long long!!!
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void Designant(){//freopen!!!
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
const int MAX=1e5+11;
int n,a[MAX][5],cnt[5],ans,f[MAX],d;
vector<int>g[5];
void reset(){
	for(int i=1;i<=n;i++){
		a[i][1]=a[i][2]=a[i][3]=0;
	}
	memset(cnt,0,sizeof(cnt));
	memset(f,0,sizeof(f));
	d=0;
	g[1].clear(),g[2].clear(),g[3].clear();
	ans=0;
	return ;
}
void solve(){
	n=read();
	for(int i=1;i<=n;i++){
		a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			cnt[1]++;
			int x=max(a[i][2],a[i][3]);
			g[1].push_back(a[i][1]-x);
			ans+=a[i][1];
		}else if(a[i][2]>=a[i][3]){
			cnt[2]++;
			int x=max(a[i][1],a[i][3]);
			g[2].push_back(a[i][2]-x);
			ans+=a[i][2];
		}else{
			cnt[3]++;
			int x=max(a[i][1],a[i][2]);
			g[3].push_back(a[i][3]-x);
			ans+=a[i][3];
		}
	}
	if(cnt[1]>n/2){
		d=cnt[1];
		for(int i=1;i<=cnt[1];i++){
			f[i]=g[1][i-1];
		}
	}else if(cnt[2]>n/2){
		d=cnt[2];
		for(int i=1;i<=cnt[2];i++){
			f[i]=g[2][i-1];
		}
	}else if(cnt[3]>n/2){
		d=cnt[3];
		for(int i=1;i<=cnt[3];i++){
			f[i]=g[3][i-1];
		}
	}else{
		printf("%d\n",ans);
		reset();
		return ;
	}
	sort(f+1,f+d+1);
	for(int i=1;i<=d-n/2;i++){
		ans-=f[i];
	}
	printf("%d\n",ans);
	reset();
	return ;
}
int main(){
	Designant();
	int T=read();
	while(T--){
		solve();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}