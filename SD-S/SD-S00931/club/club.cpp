#include<bits/stdc++.h>
typedef long long ll;
typedef std::pair<int,int> pii;
inline void rd(){}
template<typename T,typename ...U>
inline void rd(T &x,U &...args){
	T f=1;x=0;int ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	x*=f;rd(args...);
}
const int N=1e5+5;
int T,n,a[N][3],b[N],c[5];
inline void Solve(){
	rd(n);
	for(int t:{0,1,2})c[t]=0;
	for(int i=1;i<=n;i++)for(int t:{0,1,2})rd(a[i][t]);
	int ans=0;
	for(int i=1;i<=n;i++){
		int mx=std::max({a[i][0],a[i][1],a[i][2]});
		for(int t:{0,1,2}){
			if(a[i][t]==mx){
				b[i]=t;
				ans+=a[i][t];
				++c[t];
				break;
			}
		}
	}
	int d=-1;
	for(int t:{0,1,2}){
		if(c[t]>n/2)d=t;
	}
	if(d==-1){
		printf("%d\n",ans);
		return ;
	}
	std::vector<int> vec;
	for(int i=1;i<=n;i++)if(b[i]==d){
		int k=std::min(a[i][d]-a[i][(d+1)%3],a[i][d]-a[i][(d+2)%3]);
		vec.push_back(k);
	}
	std::sort(vec.begin(),vec.end());
	int len=(int)vec.size();
	for(int i=0;i<len&&i<(c[d]-n/2);i++)ans-=vec[i];
	printf("%d\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	rd(T);
	while(T--)Solve();
	return 0;
}
