#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005],b[100005],c[100005],ans,x,y,z,ma,cma,acnt,bcnt,ccnt;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0;
		acnt=bcnt=ccnt=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			ma=max({x,y,z});
			ans+=ma;
			if(ma==x){
				cma=max(y,z);
				a[++acnt]=ma-cma;
			}
			else if(ma==y){
				cma=max(x,z);
				b[++bcnt]=ma-cma;
			}
			else{
				cma=max(x,y);
				c[++ccnt]=ma-cma;
			}
		}
		if(acnt>n/2){
			sort(a+1,a+1+acnt);
			for(int i=1;i<=acnt-n/2;i++){
				ans-=a[i];
			}
		}
		if(bcnt>n/2){
			sort(b+1,b+1+bcnt);
			for(int i=1;i<=bcnt-n/2;i++){
				ans-=b[i];
			}
		}
		if(ccnt>n/2){
			sort(c+1,c+1+ccnt);
			for(int i=1;i<=ccnt-n/2;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
