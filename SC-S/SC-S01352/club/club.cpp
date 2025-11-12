#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T,n;
long long ans;
int a[N][3],c[N];
struct qaq{
	int chazhi,zubie;
}b[N];
void hang(int h,int p) {
	int cnt=0;
	for(int i=1;i<=n;i++) {
		if(b[i].zubie/10==h) c[++cnt]=b[i].chazhi;
	}
	sort(c+1,c+1+cnt);
	for(int i=1;i<=p;i++) {
		ans-=c[i];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
		int cnt1=0,cnt2=0,cnt3=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]<=a[i][2]&&a[i][1]<=a[i][3]) {
				if(a[i][2]>a[i][3]) {
					b[i].zubie=23;
					cnt2++;
					b[i].chazhi=a[i][2]-a[i][3];
				} else {
					b[i].zubie=32;
					cnt3++;
					b[i].chazhi=a[i][3]-a[i][2];
				}
			} else {
				if(a[i][2]<=a[i][1]&&a[i][2]<=a[i][3]) {
				if(a[i][1]>a[i][3]) {
					b[i].zubie=13;
					cnt1++;
					b[i].chazhi=a[i][1]-a[i][3];
				} else {
					b[i].zubie=31;
					cnt3++;
					b[i].chazhi=a[i][3]-a[i][1];
				}
			} else {
				if(a[i][3]<=a[i][1]&&a[i][3]<=a[i][2]) {
				if(a[i][1]>a[i][2]) {
					b[i].zubie=12;
					cnt1++;
					b[i].chazhi=a[i][1]-a[i][2];
				} else {
					b[i].zubie=21;
					cnt2++;
					b[i].chazhi=a[i][2]-a[i][1];
				}
			    }
			}
			}
		}
		for(int i=1;i<=n;i++) ans+=a[i][b[i].zubie/10];
		if(cnt1>n/2) hang(1,cnt1-n/2);
		if(cnt2>n/2) hang(2,cnt2-n/2);
		if(cnt3>n/2) hang(3,cnt3-n/2);
		cout<<ans<<"\n";
	}
	
	return 0; 
}