#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;long long t,n,cnt[N],c[N],num=0,ans=0,cc;struct node{long long a[5],flag;}a[N];bool cmp(node x,node y){return x.a[x.flag]>y.a[y.flag];}bool cp(long long x,long long y){return x>y;}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>t;while(t--){
		num=ans=cnt[1]=cnt[2]=cnt[3]=0;
		cin>>n;for(int i=1;i<=n;i++) cin>>a[i].a[1]>>a[i].a[2]>>a[i].a[3],cnt[a[i].flag=(a[i].a[1]>=a[i].a[2]&&a[i].a[1]>=a[i].a[3]?1:(a[i].a[2]>=a[i].a[1]&&a[i].a[2]>=a[i].a[3]?2:3))]++;sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) if(cnt[a[i].flag]>n/2) c[++num]=max((a[i].flag!=1?a[i].a[1]:0),max((a[i].flag!=2?a[i].a[2]:0),(a[i].flag!=3?a[i].a[3]:0)))-a[i].a[a[i].flag];
		for(int i=1;i<=n;i++) ans+=a[i].a[a[i].flag];sort(c+1,c+num+1,cp),cc=0;if(num) for(int i=max(cnt[1],max(cnt[2],cnt[3]))-n/2;i>=1;i--) ans+=c[++cc];
		cout<<ans<<"\n";
	}
	return 0;
}
