#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int T,n,gv[N],a[N][5],cnt1,cnt2,cnt3,ans,p[N],top;

int mi(int a,int b,int c){
	if(a>b)
		swap(a,b);
	if(b>c)
		swap(b,c);
	if(a>b)
		swap(a,b);
	if(b>c)
		swap(b,c);
	return b;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=cnt1=cnt2=cnt3=0;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		for(int i=1;i<=n;++i){
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			ans+=mx;
			if(a[i][1]==mx){
				++cnt1;
			}else if(a[i][2]==mx){
				++cnt2;
			}else{
				++cnt3;
			}
		}
		top=0;
		if(cnt1>n/2){
			int nd=cnt1-n/2;
			for(int i=1;i<=n;++i){
				int mx=max(a[i][1],max(a[i][2],a[i][3]));
				int mid=mi(a[i][1],a[i][2],a[i][3]);
				if(a[i][1]==mx)
					p[++top]=(mx-mid);
			}
			sort(p+1,p+1+top);
			for(int i=1;i<=nd;++i)
				ans-=p[i];
		}else if(cnt2>n/2){
			int nd=cnt2-n/2;
			for(int i=1;i<=n;++i){
				int mx=max(a[i][1],max(a[i][2],a[i][3]));
				int mid=mi(a[i][1],a[i][2],a[i][3]);
				if(a[i][2]==mx)
					p[++top]=(mx-mid);
			}
			sort(p+1,p+1+top);
			for(int i=1;i<=nd;++i)
				ans-=p[i];
		}else if(cnt3>n/2){
			int nd=cnt3-n/2;
			for(int i=1;i<=n;++i){
				int mx=max(a[i][1],max(a[i][2],a[i][3]));
				int mid=mi(a[i][1],a[i][2],a[i][3]);
				if(a[i][3]==mx)
					p[++top]=(mx-mid);
			}
			sort(p+1,p+1+top);
			for(int i=1;i<=nd;++i)
				ans-=p[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
