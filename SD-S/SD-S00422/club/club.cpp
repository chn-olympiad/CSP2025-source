#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a1[114514],a2[114514],a3[114514],n,m1,m2,m3,man,ans,T;
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			ll x,y,z,ma2;
			cin>>x>>y>>z;
			if(x>=y&&x>=z){
				if(y>=z) ma2=y;
				else ma2=z;
				m1++;
				a1[m1]=x-ma2;
				ans+=x;
			}
			else if(y>=x&&y>=z){
				if(x>=z) ma2=x;
				else ma2=z;
				m2++;
				a2[m2]=y-ma2;
				ans+=y;
			}
			else{
				if(x>=y) ma2=x;
				else ma2=y;
				m3++;
				a3[m3]=z-ma2;
				ans+=z;
			}
		}
		man=max(max(m1,m2),m3);
		if(man>n/2){
			if(m1>n/2){
				sort(a1+1,a1+1+m1);
				for(int i=1;i<=m1-n/2;i++) ans-=a1[i];
			}
			else if(m2>n/2){
				sort(a2+1,a2+1+m2);
				for(int i=1;i<=m2-n/2;i++) ans-=a2[i];
			}
			else{
				sort(a3+1,a3+1+m3);
				for(int i=1;i<=m3-n/2;i++) ans-=a3[i];
			}
		}
		cout<<ans<<endl;
		m1=0;
		m2=0;
		m3=0;
		ans=0;
	}
	cout<<endl;
	return 0;
}

