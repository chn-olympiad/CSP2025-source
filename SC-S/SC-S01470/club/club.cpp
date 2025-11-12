#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N][4],ans,T,n;
int cnt1,cnt2,cnt3;
struct p{
	int dd1,dd2,dd3;
	int a,b,c;
	bool vis;
}m[N];
bool cmp1(p &x,p &y){
	return x.dd1>y.dd1;
}
bool cmp2(p &x,p &y){
	return x.dd2>y.dd2;
}
bool cmp3(p &x,p &y){
	return x.dd3>y.dd3;
}
int main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cnt1=0,cnt2=0,cnt3=0,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			m[i].vis=0;
			cin>>m[i].a>>m[i].b>>m[i].c;
			m[i].dd1=m[i].a-m[i].b-m[i].c;
			m[i].dd2=m[i].b-m[i].a-m[i].c;
			m[i].dd3=m[i].c-m[i].b-m[i].a;
		}

		sort(m+1,m+1+n,cmp1);
		int i=0;
		while(cnt1<n/2&&i<n){
			i++;
			if(!m[i].vis&&(m[i].dd1>m[i].dd2)&&(m[i].dd1>m[i].dd3)){
				cnt1++;
				m[i].vis=1;
				ans+=m[i].a;
			}
		}
		if(cnt1==n/2){
			for(int i=1;i<=n;i++)m[i].dd1=-100000;
		}
		sort(m+1,m+1+n,cmp2);
		i=0;
		while(cnt2<n/2&&i<n){
			i++;
			if(!m[i].vis&&(m[i].dd2>m[i].dd1)&&(m[i].dd2>m[i].dd3)){
				cnt2++;
				m[i].vis=1;
				ans+=m[i].b;
			}
		}
		if(cnt2==n/2){
			for(int i=0;i<=n;i++)m[i].dd2=-100000;
		}
		sort(m+1,m+1+n,cmp3);
		i=0;
		while(cnt3<n/2&&i<n){
			i++;
			if(!m[i].vis&&(m[i].dd3>m[i].dd2)&&(m[i].dd3>m[i].dd1)){
				cnt3++;
				m[i].vis=1;
				ans+=m[i].c;
			}
		}
		if(cnt3==n/2){
			for(int i=0;i<=n;i++)m[i].dd3=-100000;
		}
		sort(m+1,m+1+n,cmp1);
		i=0;
		while(cnt1<n/2&&i<n){
			i++;
			if(!m[i].vis&&(m[i].dd1>m[i].dd2)&&(m[i].dd1>m[i].dd3)){
				cnt1++;
				m[i].vis=1;
				ans+=m[i].a;
			}
		}
		if(cnt1==n/2){
			for(int i=1;i<=n;i++)m[i].dd1=-100000;
		}
		sort(m+1,m+1+n,cmp2);
		i=0;
		while(cnt2<n/2&&i<n){
			i++;
			if(!m[i].vis&&(m[i].dd2>m[i].dd1)&&(m[i].dd2>m[i].dd3)){
				cnt2++;
				m[i].vis=1;
				ans+=m[i].b;
			}
		}
		if(cnt2==n/2){
			for(int i=0;i<=n;i++)m[i].dd2=-100000;
		}
		sort(m+1,m+1+n,cmp3);
		i=0;
		while(cnt3<n/2&&i<n){
			i++;
			if(!m[i].vis&&(m[i].dd3>m[i].dd2)&&(m[i].dd3>m[i].dd1)){
				cnt3++;
				m[i].vis=1;
				ans+=m[i].c;
			}
		}
		if(cnt3==n/2){
			for(int i=0;i<=n;i++)m[i].dd3=-100000;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
