#include<bits/stdc++.h>
using namespace std;
struct bbb{
	int l,a;
};
struct aaa{
	bbb a[3];
};
bool cmp(bbb a,bbb b){
	return a.a>b.a;
}
bool cmp1(aaa a,aaa b){
	return a.a[0].a-a.a[1].a>b.a[0].a-b.a[1].a;
}
aaa a[100005];
int main(){
    freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].a[0].a>>a[i].a[1].a>>a[i].a[2].a;
			a[i].a[0].l=0;
			a[i].a[1].l=1;
			a[i].a[2].l=2;
			sort(a[i].a,a[i].a+3,cmp);
		}
		sort(a+1,a+1+n,cmp1);
		int b[3];
		b[0]=n/2;
		b[1]=n/2;
		b[2]=n/2;
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(b[a[i].a[0].l]<=0){
				ans+=a[i].a[1].a;
				b[a[i].a[1].l]--;
			}
			else{
				ans+=a[i].a[0].a;
				b[a[i].a[0].l]--;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
