#include <bits/stdc++.h>
//#include <bits/extc++.h>
#define int long long
#define ret return
#define mp make_pair
#define pb push_back
#define mid (l+r>>1)
using namespace std;
//using namespace __gnu_pbds;
int read(){
	int s=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	ret s*f;
}
const int N=1e5+10;
int cnt[4],id[4],a[N][4];
bool cmp(int x,int y){ret cnt[x]>cnt[y];}
void solve(){
	int n=read(),ans=0,tot=0;
	cnt[1]=cnt[2]=cnt[3]=0;
	for(int i=1;i<=n;i++){
		a[i][1]=read();a[i][2]=read();a[i][3]=read();
		for(int j=1;j<=3;j++)if(a[i][j]>=max(a[i][1],max(a[i][2],a[i][3]))){cnt[j]++;break;}
		ans+=max(a[i][1],max(a[i][2],a[i][3]));
	}
	id[1]=1,id[2]=2,id[3]=3;sort(id+1,id+4,cmp);
	if(cnt[id[1]]<=n/2){printf("%lld\n",ans);ret;}
	priority_queue<int> q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]<max(a[i][1],max(a[i][2],a[i][3])))continue;
			if(j!=id[1])continue;q.push(max(a[i][id[2]],a[i][id[3]])-a[i][id[1]]);
		}
	}
	for(int i=1;i<=cnt[id[1]]-n/2;i++)ans+=q.top(),q.pop();
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=read();while(t--)solve();ret 0;
}
