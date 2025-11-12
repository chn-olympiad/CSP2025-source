#include<bits/stdc++.h>
using namespace std;
constexpr int N=1e5+5;
typedef long long ll;
int T,n,ans,f,a1[N],a2[N],a3[N],cnt[5],p[N],b[N],siz;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n, ans=f=siz=cnt[1]=cnt[2]=cnt[3]=0;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
			int v=max(a1[i],max(a2[i],a3[i]));
			if(a1[i]==v) p[i]=1;
			else if(a2[i]==v) p[i]=2;
			else p[i]=3;
			ans+=v;
			cnt[p[i]]++;
		}
		if(cnt[1]>(n>>1)) f=1;
		else if(cnt[2]>(n>>1)) f=2;
		else if(cnt[3]>(n>>1)) f=3;
		if(f){
			for(int i=1;i<=n;i++)
				if(p[i]==f){
					siz++;
					if(f==1) b[siz]=max(a2[i],a3[i])-a1[i];
					else if(f==2) b[siz]=max(a1[i],a3[i])-a2[i];
					else b[siz]=max(a1[i],a2[i])-a3[i];
				}
			sort(b+1,b+1+siz);
			for(int i=siz;i>(n>>1);i--)
				ans+=b[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}