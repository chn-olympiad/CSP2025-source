#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ebdl '\n'
const int N=1e5+10;

ll T;
ll n;
ll a11=0,a22=0,a33=0;
ll maxx=0;

struct node{
	int a1,a2,a3;
};
node a[N];

bool cmp1(node x,node y){
	return x.a1>y.a1;
}

bool cmp2(node x,node y){
	if(x.a1==y.a1) return x.a2<y.a2;
	return x.a1>y.a1;
}
bool cmp3(node x,node y){
	if(x.a2==y.a2) return x.a1<y.a1;
	return x.a2>y.a2;
}

void dfs(ll x,ll c){
	if(x>n){
		maxx=max(maxx,c);
		return ;
	}
	if(a11>0){
		a11--;
		dfs(x+1,c+a[x].a1);
		a11++;
	}
	if(a22>0){
		a22--;
		dfs(x+1,c+a[x].a2);
		a22++;
	}
	if(a33>0){
		a33--;
		dfs(x+1,c+a[x].a3);
		a33++;
	}
	return ;
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		a11=n/2;
		a22=n/2;
		a33=n/2;
		bool flagA=1,flagB=1;
		for(ll i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0) flagA=0;
			if(a[i].a3!=0) flagB=0;
		} 
		if(flagA){
			sort(a+1,a+1+n,cmp1);
			ll cnt=0;
			for(ll i=1;i<=n/2;i++) cnt+=a[i].a1;
			cout<<cnt<<endl;
		}
		else if(flagB){
			sort(a+1,a+1+n,cmp2);
			ll cnt1=0;
			for(ll i=1;i<=n/2;i++) cnt1+=a[i].a1;
			for(ll i=n/2+1;i<=n;i++) cnt1+=a[i].a2;
			
			sort(a+1,a+1+n,cmp3);
			ll cnt2=0;
			for(ll i=1;i<=n/2;i++) cnt2+=a[i].a2;
			for(ll i=n/2+1;i<=n;i++) cnt2+=a[i].a1;
			cout<<max(cnt1,cnt2)<<endl;
		}
		else {
			dfs(1,0);
			cout<<maxx<<endl;
			maxx=0;
		}
	}
	return 0;
}
