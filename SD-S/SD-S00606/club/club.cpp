#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int mx,ca;
}a[N],g1[N],g2[N],g3[N];
int T,n,b[5],c[5];
bool cmp(node x,node y){
	if(x.ca!=y.ca){
		return x.ca>y.ca;
	}
	return x.mx>y.mx;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		int ans=0,cnt1=0,cnt2=0,cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c[1]>>c[2]>>c[3];
			b[1]=c[1];
			b[2]=c[2];
			b[3]=c[3];
			sort(b+1,b+4);
			a[i].mx=b[3];
			a[i].ca=b[3]-b[2];
			if(b[3]==c[1]){
				++cnt1;
				g1[cnt1].mx=a[i].mx;
				g1[cnt1].ca=a[i].ca;
				continue;
			}
			if(b[3]==c[2]){
				++cnt2;
				g2[cnt2].mx=a[i].mx;
				g2[cnt2].ca=a[i].ca;
				continue;
			}
			if(b[3]==c[3]){
				++cnt3;
				g3[cnt3].mx=a[i].mx;
				g3[cnt3].ca=a[i].ca;
				continue;
			}
		}
		sort(g1+1,g1+1+cnt1,cmp);
		sort(g2+1,g2+1+cnt2,cmp);
		sort(g3+1,g3+1+cnt3,cmp);
		for(int i=1;i<=min(cnt1,n/2);i++){
			ans+=g1[i].mx;
		}
		for(int i=1;i<=min(cnt2,n/2);i++){
			ans+=g2[i].mx;
		}
		for(int i=1;i<=min(cnt3,n/2);i++){
			ans+=g3[i].mx;
		}
		if(cnt1>n/2){
			for(int i=n/2+1;i<=cnt1;i++){
				ans+=g1[i].mx-g1[i].ca;
			}
		}
		if(cnt2>n/2){
			for(int i=n/2+1;i<=cnt2;i++){
				ans+=g2[i].mx-g2[i].ca;
			}
		}
		if(cnt3>n/2){
			for(int i=n/2+1;i<=cnt3;i++){
				ans+=g3[i].mx-g3[i].ca;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
