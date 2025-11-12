#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int tot1,tot2,tot3;
int s1[N],s2[N],s3[N];
struct node{
	int w[5];
	int d;
}a[N];
long long ans;
bool cmp(int x,int y){
	return a[x].d<a[y].d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		tot1=tot2=tot3=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;++i){
			int maxn=0,maxx=0,pos;
			for(int j=1;j<=3;++j){
				cin>>a[i].w[j];
				if(a[i].w[j]>maxn){
					maxx=maxn;
					maxn=a[i].w[j];
					pos=j;
				}
				else maxx=max(maxx,a[i].w[j]);
			}
//			cout<<maxn<<" "<<pos<<'\n';
			ans+=maxn;
			if(pos==1) s1[++tot1]=i;
			else if(pos==2) s2[++tot2]=i;
			else s3[++tot3]=i;
			a[i].d=maxn-maxx;
		}
//		cout<<tot1<<" "<<tot2<<" "<<tot3<<" "<<n/2<<'\n';
		if(tot1>n/2){
			sort(s1+1,s1+tot1+1,cmp);
			for(int i=1;tot1-i>=n/2;++i) ans-=a[s1[i]].d;
		}
		if(tot2>n/2){
			sort(s2+1,s2+tot2+1,cmp);
			for(int i=1;tot2-i>=n/2;++i) ans-=a[s2[i]].d;
		}
		if(tot3>n/2){
			sort(s3+1,s3+tot3+1,cmp);
			for(int i=1;tot3-i>=n/2;++i) ans-=a[s3[i]].d;
		}
		cout<<ans<<'\n';
	}
	return 0;
}