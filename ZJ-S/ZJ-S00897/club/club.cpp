#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,INF=1e6;
struct node{
	int a[5],ma;
}a[N];
struct node2{
	int bat,id;
}b[N];
int t,n,k,ans,num,cnt[10];
bool cmp(node2 A,node2 B){
	return A.bat<B.bat;
}
void solve(){
	memset(cnt,0,sizeof(cnt));
	num=k=ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].a[1],&a[i].a[2],&a[i].a[3]);
		if(a[i].a[1]>=a[i].a[2]&&a[i].a[1]>=a[i].a[3]) a[i].ma=1;
		else if(a[i].a[2]>=a[i].a[1]&&a[i].a[2]>=a[i].a[3]) a[i].ma=2;
		else a[i].ma=3;
		cnt[a[i].ma]++;
	}
	if(cnt[1]>=cnt[2]&&cnt[1]>=cnt[3]) k=1;
	else if(cnt[2]>=cnt[1]&&cnt[2]>=cnt[3]) k=2;
	else k=3;
	for(int i=1;i<=n;i++)
		ans=ans+max(a[i].a[1],max(a[i].a[2],a[i].a[3]));
	if(cnt[k]<=n/2){
		printf("%d\n",ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(a[i].ma==k){
			num++; b[num].bat=INF; b[num].id=i;
			for(int j=1;j<=3;j++)
				if(j!=k) b[num].bat=min(b[num].bat,a[i].a[k]-a[i].a[j]);
		} 
	}
	sort(b+1,b+num+1,cmp);
	for(int i=1;i<=cnt[k]-n/2;i++) ans-=b[i].bat;
	printf("%d\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
