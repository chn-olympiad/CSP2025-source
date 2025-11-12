#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100005][4],ans=0,so,st,sh,flago,flagt;
struct node{
	long long numo,numt;
};
bool cmp(node x,node y){
	return x.numt-x.numo<y.numt-y.numo;
}
void dfs(long long l,long long cnt){
	if(l>n){
		ans=max(ans,cnt);
		return ;
	}
	if(so<n/2) so++,dfs(l+1,cnt+a[l][1]),so--;
	if(st<n/2) st++,dfs(l+1,cnt+a[l][2]),st--;
	if(sh<n/2) sh++,dfs(l+1,cnt+a[l][3]),sh--;
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		flago=1;
		flagt=1;
		for(long long i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			flago=(flago&&(a[i][2]==0)&&(a[i][3]==0));
			flagt=(flagt&&(a[i][3]==0));
		}
		if(flago){
			long long b[100005];
			for(long long i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+n+1,greater<long long>());
			for(long long i=1;i<=n/2;i++){
				ans+=b[i];
			}
			cout<<ans<<"\n";
			continue;
		}
		if(flagt){
			node b[100005];
			long long anst=0;
			for(long long i=1;i<=n;i++){
				b[i]={a[i][1],a[i][2]};
			}
			sort(b+1,b+n+1,cmp);
			for(long long i=1;i<=n;i++){
				if(i<=n/2) ans+=b[i].numo;
				else ans+=b[i].numt;
			}
			cout<<ans<<"\n";
			continue;
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}
