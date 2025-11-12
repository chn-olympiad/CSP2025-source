#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long a[100005][4];
int d[100005];
long long ch[100005];
void solve(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		d[i]=0;
		ch[i]=0;
	}
	long long ans=0;
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			d[i]=1;
			cnt1++;
			ch[i]=a[i][1]-max(a[i][2],a[i][3]);
		}
		else if(a[i][2]>=a[i][3]){
			d[i]=2;
			cnt2++;
			ch[i]=a[i][2]-max(a[i][1],a[i][3]);
		}
		else{
			cnt3++;
			d[i]=3;
			ch[i]=a[i][3]-max(a[i][1],a[i][2]);
		}
		ans+=a[i][d[i]];
	}
	if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
		printf("%lld\n",ans);
		return;
	}
	int dlt=max(cnt1,max(cnt2,cnt3))-n/2,id=0;
	if(cnt1>n/2) id=1;
	if(cnt2>n/2) id=2;
	if(cnt3>n/2) id=3;
	for(int i=1;i<=n;i++)
		if(d[i]!=id) ch[i]=1e9;
	sort(ch+1,ch+n+1);
	for(int i=1;i<=dlt;i++)
		ans-=ch[i];
	printf("%lld\n",ans);
	return;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
		solve(); 
	return 0;
}
