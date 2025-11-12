#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,sum;
int cnt1,cnt2,cnt3;
const int N=1e5+5;
struct stu{
	int d1,d2,d3;
	int cha1,cha2;
	int fi,se;
}p[N];
bool cmp(stu a,stu b){
	if(a.cha1!=b.cha1) return a.cha1>b.cha1;
	return a.cha2>b.cha2;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		sum=0;
		cnt1=0;
		cnt2=0;
		cnt3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&p[i].d1,&p[i].d2,&p[i].d3);
			if(p[i].d1>=p[i].d2&&p[i].d2>=p[i].d3){
				p[i].cha1=p[i].d1-p[i].d2;
				p[i].cha2=p[i].d2-p[i].d3;
				p[i].fi=1;p[i].se=2;
			}else if(p[i].d1>=p[i].d3&&p[i].d3>=p[i].d2){
				p[i].cha1=p[i].d1-p[i].d3;
				p[i].cha2=p[i].d3-p[i].d2;
				p[i].fi=1;p[i].se=3;
			}else if(p[i].d2>=p[i].d1&&p[i].d1>=p[i].d3){
				p[i].cha1=p[i].d2-p[i].d1;
				p[i].cha2=p[i].d1-p[i].d3;
				p[i].fi=2;p[i].se=1;
			}else if(p[i].d2>=p[i].d3&&p[i].d3>=p[i].d1){
				p[i].cha1=p[i].d2-p[i].d3;
				p[i].cha2=p[i].d3-p[i].d1;
				p[i].fi=2;p[i].se=3;
			}else if(p[i].d3>=p[i].d1&&p[i].d1>=p[i].d2){
				p[i].cha1=p[i].d3-p[i].d1;
				p[i].cha2=p[i].d1-p[i].d2;
				p[i].fi=3;p[i].se=1;
			}else if(p[i].d3>=p[i].d2&&p[i].d2>=p[i].d1){
				p[i].cha1=p[i].d3-p[i].d2;
				p[i].cha2=p[i].d2-p[i].d1;
				p[i].fi=3;p[i].se=2;
			}
		}
		sort(p+1,p+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(p[i].fi==1&&cnt1==n/2){
				if(p[i].se==2) sum+=p[i].d2,cnt2++;
				else sum+=p[i].d3,cnt3++;
			}else if(p[i].fi==2&&cnt2==n/2){
				if(p[i].se==1) sum+=p[i].d1,cnt1++;
				else sum+=p[i].d3,cnt3++;
			}else if(p[i].fi==3&&cnt3==n/2){
				if(p[i].se==1) sum+=p[i].d1,cnt1++;
				else sum+=p[i].d2,cnt2++;
			}else{
				if(p[i].fi==1) sum+=p[i].d1,cnt1++;
				else if(p[i].fi==2) sum+=p[i].d2,cnt2++;
				else if(p[i].fi==3) sum+=p[i].d3,cnt3++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}