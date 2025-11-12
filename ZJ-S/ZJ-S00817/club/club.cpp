#include<bits/stdc++.h>
using namespace std;
int T;
int a[100001][4],cnt[4],n,ans;
struct st{
	int x,id;
}b[100001];
int p[100001];
bool cmp(st x,st y){
	return x.x<y.x;
}
void sv(){
	cnt[1]=cnt[2]=cnt[3]=ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
			cnt[1]++;
			b[i].x=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
			p[i]=1;
			ans+=a[i][1];
		}
		else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
			cnt[2]++;
			b[i].x=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
			p[i]=2;
			ans+=a[i][2];
		}
		else if(a[i][3]>=a[i][2]&&a[i][3]>=a[i][1]){
			cnt[3]++;
			b[i].x=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
			p[i]=3;
			ans+=a[i][3];
		}
		b[i].id=i;
	}
	sort(b+1,b+1+n,cmp);
	int j=1;
	while(cnt[1]>n/2){
		if(p[b[j].id]==1){
			ans-=b[j].x;
			cnt[1]--;
		}
		j++;
	}
	while(cnt[2]>n/2){
		if(p[b[j].id]==2){
			ans-=b[j].x;
			cnt[2]--;
		}
		j++;
	}
	while(cnt[3]>n/2){
		if(p[b[j].id]==3){
			ans-=b[j].x;
			cnt[3]--;
		}
		j++;
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--) sv();
	return 0;
}
