#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const ll N=2e5+10;
//#define DBL
using namespace std;
int n,ii,tp,hf,tot=0,T;
ll ans=0;
struct nub{
	int vl[4];
}a[N];
queue<int>q[4];
int ca[N];
int dy(int x){
	if(x>1){
		return 1;
	}
	return 2;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;hf=n>>1;
		bool fff=0;tot=0;
		ans=0;
		for(int j=1;j<=3;j++){
			q[j].push(1);q[j].pop();
			while(!q[j].empty()){
				q[j].pop();
			}
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].vl[1]>>a[i].vl[2]>>a[i].vl[3];
		}
		for(int i=1;i<=n;i++){
			tp=-1;
			for(int j=1;j<=3;j++){
				if(a[i].vl[j]>=tp){
					ii=j;
					tp=a[i].vl[j];
				}
			}
			ans+=a[i].vl[ii];
			q[ii].push(i);
		}
		for(int j=1;j<=3;j++){
			if(q[j].size()>hf){
				ii=j;fff=1;break;
			}
		}
		if(fff){
			while(!q[ii].empty()){
				tot++;tp=q[ii].front();
				ca[tot]=a[tp].vl[ii]-max(a[tp].vl[dy(ii)],a[tp].vl[6-ii-dy(ii)]);
				q[ii].pop();
			}
			sort(ca+1,ca+tot+1);
			tot=tot-hf;
			for(int i=1;i<=tot;i++){
				ans-=ca[i];
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}

