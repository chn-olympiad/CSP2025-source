#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct peo{
	ll bm1,bm2,bm3;
	ll getcha()const{
		ll maxn=max(max(bm1,bm2),bm3),minn=min(min(bm1,bm2),bm3);
		return maxn-(bm1+bm2+bm3-maxn-minn);
	}
	bool operator<(peo a)const{
		return getcha()<a.getcha();
	}
};
struct cmp{
	bool operator()(peo a,peo b){
		return b<a; 
	}
};
peo temppoe;
priority_queue<peo,vector<peo>,cmp> used[5];
ll t,n,ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(cin>>t;t>0;t--){
		cin>>n;
		ans=0;
		while(!used[1].empty()){
			used[1].pop();
		}
		while(!used[2].empty()){
			used[2].pop();
		}
		while(!used[3].empty()){
			used[3].pop();
		}
		for(int i=1;i<=n;i++){
			cin>>temppoe.bm1>>temppoe.bm2>>temppoe.bm3;
			if(temppoe.bm1>=temppoe.bm2 &&temppoe.bm1>=temppoe.bm3){
				used[1].push(temppoe);
			}else if(temppoe.bm3>=temppoe.bm2 &&temppoe.bm3>=temppoe.bm1){
				used[3].push(temppoe);
			}else if(temppoe.bm2>=temppoe.bm1 &&temppoe.bm2>=temppoe.bm3){
				used[2].push(temppoe);
			}
			ans+=max(max(temppoe.bm1,temppoe.bm2),temppoe.bm3);
		}
		while(used[1].size()>n/2){
			ans-=used[1].top().getcha(); 
			used[1].pop();
		}
		while(used[2].size()>n/2){
			ans-=used[2].top().getcha(); 
			used[2].pop();
		}
		while(used[3].size()>n/2){
			ans-=used[3].top().getcha(); 
			used[3].pop();
		}
		cout<<ans<<'\n';
	}
	return 0;
}

