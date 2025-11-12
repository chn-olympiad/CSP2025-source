#include<bits/stdc++.h>
using namespace std;
#define N 100005
#define endl '\n'
#define int long long 
int n,t;
struct node{
	int a1;
	int a2;
	int a3;
}m[N];
int m1[N],m2[N],m3[N];
int cnt1;
int cnt2;
int cnt3;
bool cmp(int a,int b){
	return a<b;
}
void solve(){
	int ans=0;
	cnt1=0;
	cnt2=0;
	cnt3=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].a1>>m[i].a2>>m[i].a3;
		int mx=max(m[i].a1,max(m[i].a2,m[i].a3));
		if(mx==m[i].a1){
			m1[++cnt1]=mx-max(m[i].a2,m[i].a3);
			ans+=mx;
			continue;
		}
		if(mx==m[i].a2){
			m2[++cnt2]=mx-max(m[i].a1,m[i].a3);
			ans+=mx;
			continue;
		}
		if(mx==m[i].a3){
			m3[++cnt3]=mx-max(m[i].a1,m[i].a2);
			ans+=mx;
			continue;
		}
	}
	if(cnt1>n/2){
		sort(m1+1,m1+cnt1+1,cmp);
		for(int i=1;i<=cnt1-n/2;i++){
			ans-=m1[i];
		}
	}
	if(cnt2>n/2){
		sort(m2+1,m2+cnt2+1,cmp);
		for(int i=1;i<=cnt2-n/2;i++){
			ans-=m2[i];
		}
	}
	if(cnt3>n/2){
		sort(m3+1,m3+cnt3+1,cmp);
		for(int i=1;i<=cnt3-n/2;i++){
			ans-=m3[i];
		}
	}
	cout<<ans<<endl;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
