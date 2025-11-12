#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e4+5;
ll n,a[N][5],cnta,cntb,cntc,ans;
void solve(){
	ans=cnta=cntb=cntc=0;
	cin>>n;
	priority_queue<ll,vector<ll> > pqa,pqb,pqc;
	for(int i=1;i<=n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		ans+=max(max(a[i][0],a[i][1]),a[i][2]);
		if(a[i][0]==max(max(a[i][0],a[i][1]),a[i][2])){
			cnta++;
			pqa.push(max(a[i][1],a[i][2])-a[i][0]);
		}else if(a[i][1]==max(max(a[i][0],a[i][1]),a[i][2])){
			cntb++;
			pqb.push(max(a[i][0],a[i][2])-a[i][1]);
		}else if(a[i][2]==max(max(a[i][0],a[i][1]),a[i][2])){
			cntc++;
			pqc.push(max(a[i][0],a[i][1])-a[i][2]);
		}
	}
	if(cnta<=n/2&&cntb<=n/2&&cntc<=n/2){
		cout<<ans<<"\n";
		return ;
	}else if(cnta>n/2){
		while(cnta>n/2) ans+=pqa.top(),pqa.pop(),cnta--;
		cout<<ans<<"\n";
	}else if(cntb>n/2){
		while(cntb>n/2) ans+=pqb.top(),pqb.pop(),cntb--;
		cout<<ans<<"\n";
	}else if(cntc>n/2){
		while(cntc>n/2) ans+=pqc.top(),pqc.pop(),cntc--;
		cout<<ans<<"\n";
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int _;
	cin>>_;
	while(_--) solve();
	return 0; 
}
