#include<bits/stdc++.h>
using namespace std;
#define int long long
#define R read()
inline int read(){
	int re=0;
	char ch;
	while (1){
		ch=getchar();
		if ('0'<=ch and ch<='9')	break;
	}
	while (1){
		re=re*10+ch-'0';
		ch=getchar();
		if ('0'>ch or ch>'9')	return re;
	}
}
const int N=1e5+5;
int s[3][N],cnt[3],n;
int val[3][N];
int ans;
int www[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();
	while(t--){
		ans=cnt[0]=cnt[1]=cnt[2]=0;
		n=read();
		for (int i=1;i<=n;i++){
			int maxx=-1,jj;
			for (int j=0;j<3;j++){
				val[j][i]=read();
				if (maxx<val[j][i])
					maxx=val[j][i],jj=j;
			}
			s[jj][++cnt[jj]]=i;
			ans+=val[jj][i];
		}
		if (cnt[0]>n/2){
			for (int i=1;i<=cnt[0];i++)	www[i]=val[0][s[0][i]]-max(val[1][s[0][i]],val[2][s[0][i]]);
			sort(www+1,www+cnt[0]+1);
			for (int i=1;i<=cnt[0]-n/2;i++)	ans-=www[i];
		}
		if (cnt[1]>n/2){
			for (int i=1;i<=cnt[1];i++)	www[i]=val[1][s[1][i]]-max(val[0][s[1][i]],val[2][s[1][i]]);
			sort(www+1,www+cnt[1]+1);
			for (int i=1;i<=cnt[1]-n/2;i++)	ans-=www[i];
		}
		if (cnt[2]>n/2){
			for (int i=1;i<=cnt[2];i++)	www[i]=val[2][s[2][i]]-max(val[1][s[2][i]],val[0][s[2][i]]);
			sort(www+1,www+cnt[2]+1);
			for (int i=1;i<=cnt[2]-n/2;i++)	ans-=www[i];
		}
		cout<<ans<<"\n";
	}
}

