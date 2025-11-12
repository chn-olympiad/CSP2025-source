#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T;
int n;
struct node{
	int num,id;
}a[N],b[N],c[N];
bool cmp(node x,node y){
	return x.num>y.num;
}
int x,y;
int cnt1,cnt2,cnt3;
int vis[N];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].num>>b[i].num>>c[i].num;
			ans+=c[i].num;
			a[i].num-=c[i].num,b[i].num-=c[i].num,c[i].num=0;
			a[i].id=b[i].id=c[i].id=i;
			vis[i]=0;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		a[n+1].num=b[n+1].num=-1;
		cnt1=cnt2=cnt3=0;
		x=y=1;
		while((cnt1<n/2||cnt2<n/2)&&a[x].num>=0&&b[y].num>=0){
			while(x<=n&&vis[a[x].id])	x++;
			while(y<=n&&vis[b[y].id])	y++;
			if((cnt1<n/2&&a[x].num>=b[y].num)||cnt2==n/2){
				cnt1++;
				ans+=a[x].num;
				vis[a[x].id]=1;
			}
			else if((cnt2<n/2&&b[y].num>a[x].num)||cnt1==n/2){
				cnt2++;
				ans+=b[y].num;
				vis[b[y].id]=1;
			}
		}
		cnt3=n/2;
		while((cnt1<n/2||cnt2<n/2)&&cnt1+cnt2<n-cnt3){
			while(x<=n&&vis[a[x].id])	x++;
			while(y<=n&&vis[b[y].id])	y++;
			if((cnt1<n/2&&a[x].num>=b[y].num)||cnt2==n/2){
				cnt1++;
				ans+=a[x].num;
				vis[a[x].id]=1;
			}
			else if((cnt2<n/2&&b[y].num>a[x].num)||cnt1==n/2){
				cnt2++;
				ans+=b[y].num;
				vis[b[y].id]=1;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
