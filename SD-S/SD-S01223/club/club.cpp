#include<bits/stdc++.h>
using namespace std;
#define N 200007
#define int long long
#define mp make_pair
#define pb push_back
#define A first
#define B second
#define pii pair<int,int>
int T,n,a[N][4],ans;
bool bA[N],bB[N],bC[N];
vector<int>lA,lB,lC;
vector<pair<int,pii> >t;
pii suBmax(int x,int y,int z){
	pii j[]={{x,1},{y,2},{z,3}};
	sort(j,j+3);
	return j[1];
}bool cmp(pair<int,pii> x,pair<int,pii> y){
	return x.B.A<y.B.A;
}
signed main(void){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;ans=0;
		memset(bA,0,sizeof bA);
		memset(bB,0,sizeof bB);
		memset(bC,0,sizeof bC);
		lA.clear();lB.clear();lC.clear();
		for(int i=1;i<=n;++i){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int ma=max(a[i][1],max(a[i][2],a[i][3]));
			if(ma==a[i][1]) lA.pb(i);
			else if(ma==a[i][2]) lB.pb(i);
			else lC.pb(i);
		}t.clear();
		if(lA.size()*2>n){
			for(auto i:lA) {
				auto k=suBmax(a[i][1],a[i][2],a[i][3]);
				t.pb({i,{a[i][1]-k.A,k.B}});
			}
			sort(t.begin(),t.end(),cmp);
			for(int i=0;i<(lA.size()-n/2);++i){
				int k=t[i].A;bA[k]=1;
				if(t[i].B.B==1) (a[k][1]==a[k][2]?lB.pb(k):lC.pb(k));
				else if(t[i].B.B==2) lB.pb(k);
				else lC.pb(k);
			}
		}t.clear();
		if(lB.size()*2>n){
			for(auto i:lB) {
				auto k=suBmax(a[i][1],a[i][2],a[i][3]);
				t.pb({i,{a[i][2]-k.A,k.B}});
			}
			sort(t.begin(),t.end(),cmp);
			for(int i=0;i<(lB.size()-n/2);++i){
				int k=t[i].A;bB[k]=1;
				if(t[i].B.B==2) (a[k][2]==a[k][1]?lA.pb(k):lC.pb(k));
				else if(t[i].B.B==1) lA.pb(k);
				else lC.pb(k);
			}
		}t.clear();
		if(lC.size()*2>n){
			for(auto i:lC) {
				auto k=suBmax(a[i][1],a[i][2],a[i][3]);
				t.pb({i,{a[i][3]-k.A,k.B}});
			}
			sort(t.begin(),t.end(),cmp);
			for(int i=0;i<(lC.size()-n/2);++i){
				int k=t[i].A;bC[k]=1;
				if(t[i].B.B==3) (a[k][3]==a[k][1]?lA.pb(k):lB.pb(k));
				else if(t[i].B.B==1) lA.pb(k);
				else lB.pb(k);
			}
		}for(auto i:lA) if(!bA[i])
			ans+=a[i][1];
		for(auto i:lB) if(!bB[i])
			ans+=a[i][2];
		for(auto i:lC) if(!bC[i])
			ans+=a[i][3];
		cout<<ans<<'\n';
	}cout<<endl;
	return 0;
}//?? expected
