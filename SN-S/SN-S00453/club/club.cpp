#include<bits/stdc++.h>
#define ll int
const ll maxn=100000+5;
using namespace std;
ll t,n,ans;
struct c1{
	ll a1,nm;
};
struct c2{
	c1 b[5];
}a[maxn];
struct c3{
	ll p,id;
};
bool cmp(c1 b1,c1 b2){
	return b1.a1>b2.a1;
}
bool cmp2(c3 b1,c3 b2){
	return b1.p>b2.p;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ll pd=0,pd2=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].b[1].a1>>a[i].b[2].a1>>a[i].b[3].a1;
			if(a[i].b[2].a1!=0||a[i].b[3].a1!=0){
				pd=1;
			}
			if(a[i].b[2].a1!=0&&a[i].b[2].a1!=20000){
				pd2=1;
			}
			a[i].b[1].nm=1;a[i].b[2].nm=2;a[i].b[3].nm=3;
			sort(a[i].b+1,a[i].b+1+3,cmp);
		}
		if(pd==0){
			ll h[maxn],cnt=1;
			for(int i=1;i<=n;i++){
				h[cnt]=a[i].b[1].a1;
				cnt++;
			}
			sort(h+1,h+cnt);
			for(int i=n;i>=n/2;i--){
				ans+=h[i];
			}
		}
		else{
			if(pd2==0){
				for(int i=1;i<=n;i++){
					ans+=a[i].b[1].a1;
				}
			}
			else{
				int i;
				c3 h[4][maxn/2];
				ll c[4]={0,1,1,1};
				for(i=1;i<=n;i++){
					if(a[i].b[1].nm==1){
						h[1][c[1]].id=i;
						h[1][c[1]].p=a[i].b[1].a1;
						c[1]++;
					}
					else if(a[i].b[1].nm==2){
						h[2][c[2]].id=i;
						h[2][c[2]].p=a[i].b[1].a1;
						c[2]++;
					}
					else{
						h[3][c[3]].id=i;
						h[3][c[3]].p=a[i].b[1].a1;
						c[3]++;
					}
				}
				sort(h[1]+1,h[1]+c[1],cmp2);
				sort(h[2]+1,h[2]+c[2],cmp2);
				sort(h[3]+1,h[3]+c[3],cmp2);
				c[1]--;
				c[2]--;
				c[3]--;
				int x[3];
				x[1]=c[1];
				x[2]=c[2];
				x[3]=c[3];
				for(i=1;i<=c[1];i++){
					//cout<<h[1][i].p<<" ";
					ans+=h[1][i].p;
				}
				//cout<<"\n";
				for(i=1;i<=c[2];i++){
					//cout<<h[2][i].p<<" ";
					ans+=h[2][i].p;
				}
				//cout<<"\n";
				for(i=1;i<=c[3];i++){
					//cout<<h[3][i].p<<" ";
					ans+=h[3][i].p;
				}
				if((c[1])>(n/2)){
					for(i=c[1];i>n/2;i--){
						ans=ans+a[h[1][i].id].b[2].a1-a[h[1][i].id].b[1].a1;
						h[a[i].b[2].nm][++c[a[i].b[2].nm]].p=a[i].b[2].a1;
						h[a[i].b[2].nm][++c[a[i].b[2].nm]].id=a[i].b[2].nm;
					}
				}
				if((c[2])>(n/2)){
					for(int i=c[2];i>x[2];i--){
						ans=ans+a[h[2][i].id].b[3].a1-a[h[2][i].id].b[2].a1;
					}
					for(i=x[2];i>n/2;i--){
						ans=ans+a[i].b[2].a1-a[i].b[1].a1;
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
