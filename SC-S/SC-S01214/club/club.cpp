#include<bits/stdc++.h>
using namespace std;
long long a[100002][4],b[100002],c[100002],d[100002];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long n,t,x,y,z,cnt1,cnt2,cnt3,ans,num,num2;
	cin>>t;
	while(t--){
		cnt1=0,cnt2=0,cnt3=0,ans=0,num=0,num2=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			x=max(a[i][1],max(a[i][2],a[i][3]));
			y=min(a[i][1],min(a[i][2],a[i][3]));
			if(x==a[i][1]) b[i]=1,cnt1++;
			else if(x==a[i][2]) b[i]=2,cnt2++;
			else b[i]=3,cnt3++;
			c[i]=x-a[i][1]-a[i][2]-a[i][3]+x+y;
		}
		for(int i=1;i<=n;i++){
			ans+=a[i][b[i]];
		}
		if(cnt1<=n/2&&cnt2<=n/2&&cnt3<=n/2){
			cout<<ans<<endl;
		}
		else{
			z=max(cnt1,max(cnt2,cnt3));
			if(z==cnt1) z=1;
			else if(z==cnt2) z=2;
			else z=3;
			for(int i=1;i<=n;i++){
				if(b[i]==z) d[++num]=c[i];
			}
			sort(d+1,d+1+num);
			if(z==1) num2=cnt1;
			else if(z==2) num2=cnt2;
			else num2=cnt3;
			num2-=(n/2);
			for(int i=1;i<=num2;i++) ans-=d[i];
			cout<<ans<<endl;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=3;j++) a[i][j]=0;
		for(int i=1;i<=n;i++) b[i]=0,c[i]=0;
		for(int i=1;i<=num;i++) d[i]=0;
	}
	return 0;
}