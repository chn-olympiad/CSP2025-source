#include <bits/stdc++.h>
using namespace std;
struct cy{
	long long best,cnt,cha;
};
long long n,a[100001],b[100001],c[100001],ans=0,cnta=0,cntb=0,cntc=0,move,j,t;
cy d[100001];
bool cmp(cy a,cy b){
	if(a.cha<b.cha){
		return 1;
	}
	else{
		return 0;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0,cnta=0,cntb=0,cntc=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				d[i].best=1;
				d[i].cha=a[i]-max(b[i],c[i]);
				cnta++;
				ans+=a[i];
			}
			else if(b[i]>a[i]&&b[i]>=c[i]){
				d[i].best=2;
				d[i].cha=b[i]-max(a[i],c[i]);
				cntb++;
				ans+=b[i];
			}
			else{
				d[i].best=3;
				d[i].cha=c[i]-max(a[i],b[i]);
				cntc++;
				ans+=c[i];
			}
		}
		sort(d,d+n,cmp);
		if(cnta>n/2){
			move=cnta-n/2;
			j=1;
			while(move){
				if(d[j].best==1){
					ans-=d[j].cha;
					move--;
				}
				j++;
			}
		}
		else if(cntb>n/2){
			move=cntb-n/2;
			j=1;
			while(move){
				if(d[j].best==2){
					ans-=d[j].cha;
					move--;
				}
				j++;
			}
		}
		else if(cntc>n/2){
			move=cntc-n/2;
			j=1;
			while(move){
				if(d[j].best==3){
					ans-=d[j].cha;
					move--;
				}
				j++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 