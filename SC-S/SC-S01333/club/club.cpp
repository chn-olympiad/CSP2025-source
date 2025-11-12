#include<bits/stdc++.h>
using namespace std;
int t,n,k;
int a[100005],b[100005],c[100005],x[100005],y[100005],z[100005];
int cnt1=0,cnt2=0,cnt3=0;
long long sum=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		k=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>=b[i]&&a[i]>=c[i]){
				cnt1++;
				sum+=a[i];
				x[cnt1]=min(a[i]-b[i],a[i]-c[i]);
			}
			else if(b[i]>=a[i]&&b[i]>=c[i]){
				cnt2++;
				sum+=b[i];
				y[cnt2]=min(b[i]-a[i],b[i]-c[i]);
			}
			else if(c[i]>=a[i]&&c[i]>=b[i]){
				cnt3++;
				sum+=c[i];
			    z[cnt3]=min(c[i]-a[i],c[i]-b[i]);
			}
		}
	    if(cnt1>k){
			sort(x+1,x+cnt1+1);
			for(int i=1;i<=cnt1-k;i++){
				sum-=x[i];
			}
		}
		if(cnt2>k){
			sort(y+1,y+cnt2+1);
			for(int i=1;i<=cnt2-k;i++){
				sum-=y[i];
			}
		}
		if(cnt3>k){
			sort(z+1,z+cnt3+1);
			for(int i=1;i<=cnt3-k;i++){
				sum-=z[i];
			}
		}
		cout<<sum<<'\n';
		cnt1=0;
		cnt2=0;
		cnt3=0;
		sum=0;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		memset(z,0,sizeof(z));
	}
	return 0;
}