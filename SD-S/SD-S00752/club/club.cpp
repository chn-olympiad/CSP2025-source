#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
template<typename T> void read(T &x){
	x=0;int f=0;char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) f=(c=='-');
	for(;c>='0'&&c<='9';c=getchar()) x=x*10+c-'0';
	if(f) x=-x; 
}
int n,m;
int f[4][N],cnt[4];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
	while(T--){
		read(n);
		cnt[1]=cnt[2]=cnt[3]=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			int a1,a2,a3;
			read(a1),read(a2),read(a3);
			if(a1>=a2&&a1>=a3){
				ans+=a1;
				f[1][++cnt[1]]=max(a2,a3)-a1;
			}else if(a2>=a1&&a2>=a3){
				ans+=a2;
				f[2][++cnt[2]]=max(a1,a3)-a2;
			}else{
				ans+=a3;
				f[3][++cnt[3]]=max(a1,a2)-a3;
			}
		}
		int p=0;
		for(int i=1;i<=3;i++) if(cnt[i]>n/2) p=i;
		if(p){
			sort(f[p]+1,f[p]+cnt[p]+1);
			for(int i=n/2+1;i<=cnt[p];i++) ans+=f[p][i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}


