#include<bits/stdc++.h>
using namespace std;
long long T,sa,sb,sc,ans,ta[100005],tb[100005],tc[100005],sum[100005],n,a[100006],b[100005],c[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		sa=sb=sc=ans=0;
		memset(ta,0,sizeof(ta));
		memset(tb,0,sizeof(tb));
		memset(tc,0,sizeof(tc));
		memset(sum,0,sizeof(sum));
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				sa++,ta[sa]=i,ans+=a[i];
			}
			else if(b[i]>a[i]&&b[i]>c[i]){
				sb++,tb[sb]=i,ans+=b[i];
			}
			else {
				sc++,tc[sc]=i,ans+=c[i];
			}
		}
		if(sa>n/2){
			for(int i=1;i<=sa;i++){
				sum[i]=a[ta[i]]-max(b[ta[i]],c[ta[i]]);
			}
			sort(sum+1,sum+sa+1);
			for(int i=1;i<=sa-n/2;i++){
				ans-=sum[i];
			}
		}
		else if(sb>n/2){
			for(int i=1;i<=sb;i++){
				sum[i]=b[tb[i]]-max(a[tb[i]],c[tb[i]]);
			}
			sort(sum+1,sum+sb+1);
			for(int i=1;i<=sb-n/2;i++){
				ans-=sum[i];
			}
		}
		else {
			for(int i=1;i<=sc;i++){
				sum[i]=c[tc[i]]-max(a[tc[i]],b[tc[i]]);
			}
			sort(sum+1,sum+sc+1);
			for(int i=1;i<=sc-n/2;i++){
				ans-=sum[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
