#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int a[N][4],b[4];
vector<int> c[4];
bool cmp(vector<int> x,vector<int> y){
	return x.size()>y.size();
}
bool cmp2(int x,int y){
	return c[x].size()>c[y].size();
}
struct node{
	int d,stu;
	bool operator<(const node &o)const{
		return d<o.d;
	}
};
void solve(){
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i][1]>>a[i][2]>>a[i][3];
	
	for(int i=1;i<=3;i++) c[i].clear();
	for(int i=1;i<=n;i++){
		int maxn=0;
		for(int j=1;j<=3;j++) if(a[i][maxn]<a[i][j]) maxn=j;
		c[maxn].push_back(i);
	}
	for(int i=1;i<=3;i++) b[i]=i;
	sort(b+1,b+3+1,cmp2);
	sort(c+1,c+3+1,cmp);
	int szc1=c[1].size();
	if(szc1<=n/2){
		ll ans=0;
		for(int i=1;i<=3;i++){
			int sz=c[i].size();
			for(int j=0;j<sz;j++) ans+=a[c[i][j]][b[i]];
		}
		cout<<ans<<'\n';
		return;
	}
	else{
		ll ans=0;
		for(int i=1;i<=3;i++){
			int sz=c[i].size();
			//cout<<sz<<' ';
			for(int j=0;j<sz;j++){
				ans+=a[c[i][j]][b[i]];
			}
		}
		vector<node> t;
		int sz=c[1].size();
		int tmp=b[1];
		//cout<<tmp<<'\n';
		for(int i=0;i<sz;i++){
			for(int j=1;j<=3;j++) if(j!=1){
				t.push_back((node){a[c[1][i]][tmp]-a[c[1][i]][b[j]],c[1][i]});
			}
		}
		sort(t.begin(),t.end());
		int lent=t.size(),cnt=0;
		//for(int i=0;i<lent;i++) cout<<t[i].d<<' '<<t[i].stu<<'\n';
		//cout<<'\n';
		map<int,bool> mp;
		int re=c[1].size()-n/2;
		for(int i=0;i<lent;i++){
			if(cnt==re) break;
			int d=t[i].d,stu=t[i].stu;
			if(mp[stu]) continue;
			mp[stu]=true;
			ans-=d;
			cnt++;
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;cin>>t;
	while(t--) solve();
	return 0;
}
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
