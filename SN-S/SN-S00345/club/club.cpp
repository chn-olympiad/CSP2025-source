#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n;
int a[100005][4];
int oo[100005],tt[100005],dd[100005];
int s[4],bg,nu,ml,ans;
int dud;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		for(int i=1;i<=s[1];++i)oo[i]=0;
		for(int i=1;i<=s[2];++i)tt[i]=0;
		for(int i=1;i<=s[3];++i)dd[i]=0;
		cin>>n;
		s[1]=0;
		s[2]=0;
		s[3]=0;
		ans=0;
		for(int i=1;i<=n;++i){
			bg=-1;
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>bg){
				bg=a[i][1];
				nu=1;
			}
			if(a[i][2]>bg){
				bg=a[i][2];
				nu=2;
			}
			if(a[i][3]>bg){
				bg=a[i][3];
				nu=3;
			}
			s[nu]++;
			ans+=bg;
			ml=-1;
			for(int j=1;j<=3;++j){
				if(j!=nu){
					ml=max(ml,a[i][j]);
				}
			}
			if(nu==1){
				oo[s[1]]=bg-ml;
			}
			if(nu==2){
				tt[s[2]]=bg-ml;
			}
			if(nu==3){
				dd[s[3]]=bg-ml;
			}
		}
		if(s[1]>n/2){
			dud=s[1]-(n/2);
			sort(oo+1,oo+s[1]+1);
			for(int i=1;i<=dud;++i){
				ans-=oo[i];
			}
		}
		else if(s[2]>n/2){
			dud=s[2]-(n/2);
			sort(tt+1,tt+s[2]+1);
			for(int i=1;i<=dud;++i){
				ans-=tt[i];
			}
		}
		else if(s[3]>n/2){
			dud=s[3]-(n/2);
			sort(dd+1,dd+s[3]+1);
			for(int i=1;i<=dud;++i){
				ans-=dd[i];
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
