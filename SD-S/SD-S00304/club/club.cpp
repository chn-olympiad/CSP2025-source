#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb(x) push_back(x)
using namespace std;
mt19937_64 rd(time(0));
const ll N=1e5+5;
ll n,p[N],t,fen[N],a[N][5],duo[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll ans=0,cnt=0,yi=0,er=0,san=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				yi++;fen[i]=1;ans+=a[i][1];
				if(a[i][2]>=a[i][3]){
					duo[i]=a[i][1]-a[i][2];
				}
				else{
					duo[i]=a[i][1]-a[i][3];
				}
			}
			else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
				er++;fen[i]=2;ans+=a[i][2];
				if(a[i][1]>=a[i][3]){
					duo[i]=a[i][2]-a[i][1];
				}
				else{
					duo[i]=a[i][2]-a[i][3];
				}
			}
			else {
				san++;fen[i]=3;ans+=a[i][3];
				if(a[i][1]>=a[i][2]){
					duo[i]=a[i][3]-a[i][1];
				}
				else{
					duo[i]=a[i][3]-a[i][2];
				}
			}
		}
		ll xu=0;
		if(yi>n/2){
			xu=yi-n/2;
			for(int i=1;i<=n;i++){
				if(fen[i]==1)p[++cnt]=duo[i];
			}
		}
		else if(er>n/2){
			xu=er-n/2;
			for(int i=1;i<=n;i++){
				if(fen[i]==2)p[++cnt]=duo[i];
			}
		}
		else if(san>n/2){
			xu=san-n/2;
			for(int i=1;i<=n;i++){
				if(fen[i]==3)p[++cnt]=duo[i];
			}
		}
		sort(p+1,p+cnt+1);
		for(int i=1;i<=xu;i++)ans-=p[i];
		cout<<ans<<endl;
	} 
	return 0;
}
//Ren5Jie4Di4Ling5%

