#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<1)+(s<<3)+(ch^48);
		ch=getchar();
	}
	return s*f;
}
template <typename T> void getmin(T &a,T b){
	if(b<a) a=b;
	return;
}
template <typename T> void getmax(T &a,T b){
	if(b>a) a=b;
	return;
}
int T;
int n;
int mp[100005][4];
int mxid[100005];
int cnt[4];
int a[100005],m;
ll ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(mp,0,sizeof(mp));
		memset(mxid,0,sizeof(mxid));
		memset(cnt,0,sizeof(cnt));
		memset(a,0,sizeof(a));
		m=ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				mp[i][j]=read();
				if(mp[i][j]>=mp[i][mxid[i]]) mxid[i]=j;
			}
			++cnt[mxid[i]];
		}
		int mxcnt=max(max(cnt[1],cnt[2]),cnt[3]);
		if(mxcnt<=n/2){
			for(int i=1;i<=n;++i) ans+=mp[i][mxid[i]];
		}
		else{
//			puts("y");
			int mg=1;
			for(int i=1;i<=3;++i) if(cnt[i]>=cnt[mg]) mg=i;
			for(int i=1;i<=n;++i){
				ans+=mp[i][mxid[i]];
				if(mxid[i]!=mg) continue;
				int tmp=1e9;
				for(int j=1;j<=3;++j){
					if(j==mg) continue;
					getmin(tmp,mp[i][mg]-mp[i][j]);
				}
				a[++m]=tmp;
			}
			sort(a+1,a+m+1);
			for(int i=1;i<=mxcnt-(n/2);++i){
				ans-=a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}