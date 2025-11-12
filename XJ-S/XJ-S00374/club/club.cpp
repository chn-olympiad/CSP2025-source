#include<bits/stdc++.h>
#define LL long long

using namespace std;

struct node{
	LL f,s,t;
};

const int N=1e5+5;
int n;
node a[N];
node a1[N],a2[N],a3[N];
int cnt1=0,cnt2=0,cnt3=0;

bool cmp(int p,int q){
	return p>q;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		LL ans=0;
		cnt1=cnt2=cnt3=0;
		for(int i=1;i<=n;i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
			if(a[i].f>a[i].s){
				if(a[i].f>a[i].t){
					a1[++cnt1]=a[i];
					ans+=a[i].f;
				}else{
					a3[++cnt3]=a[i];
					ans+=a[i].t;
				}
			}else{
				if(a[i].s>a[i].t){
					a2[++cnt2]=a[i];
					ans+=a[i].s;
				}else{
					a3[++cnt3]=a[i];
					ans+=a[i].t;
				}
			}
		}
		if(cnt1>n/2){
			LL b1[N];
			for(int i=1;i<=cnt1;i++){
				b1[i]=max(a1[i].s-a1[i].f,a1[i].t-a1[i].f);
			}
			sort(b1+1,b1+1+cnt1,cmp);
			for(int i=1;i<=cnt1-n/2;i++){
				ans+=b1[i];
			}
		}
		if(cnt2>n/2){
			LL b2[N];
			for(int i=1;i<=cnt2;i++){
				b2[i]=max(a2[i].f-a2[i].s,a2[i].t-a2[i].s);
			}
			sort(b2+1,b2+1+cnt2,cmp);
			for(int i=1;i<=cnt2-n/2;i++){
				ans+=b2[i];
			}
		}
		if(cnt3>n/2){
			LL b3[N];
			for(int i=1;i<=cnt3;i++){
				b3[i]=max(a3[i].f-a3[i].t,a3[i].s-a3[i].t);
			}
			sort(b3+1,b3+1+cnt3,cmp);
			for(int i=1;i<=cnt3-n/2;i++){
				ans+=b3[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
