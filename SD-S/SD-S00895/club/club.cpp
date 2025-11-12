#include<bits/stdc++.h>

#define _vc_(_6,_5,_4,_3,_2,_1,_,...) _
#define _vc(a...) _vc_(a,6,5,4,3,2,1)
#define _ct_(a,b) a##b
#define _ct(a,b) _ct_(a,b)
#define deb1(a) <<#a<<"="<<(a)<<"; "
#define deb2(a,b...) deb1(a)deb1(b)
#define deb3(a,b...) deb1(a)deb2(b)
#define deb4(a,b...) deb1(a)deb3(b)
#define deb5(a,b...) deb1(a)deb4(b)
#define deb6(a,b...) deb1(a)deb5(b)
#define deb(a...) cerr<<string(_dep*3,' ')<<"deb"<<__LINE__<<"|:" _ct(deb,_vc(a)) (a) <<endl
#define int long long
unsigned _dep;

using namespace std;

int n;
vector<int>C[3];

void sol(){
	cin>>n;int ans=0;C[0]=C[1]=C[2]={};
	for(int i=1;i<=n;++i){
		int a[3];for(int&v:a)cin>>v;
		int p=max_element(a+0,a+3)-a;
		int va=a[p];
		ans+=va;
		a[p]=-1;
		C[p].push_back(*max_element(a+0,a+3) - va);
	}
	for(int i=3;i--;)sort(C[i].begin(),C[i].end());
	for(int i=3;i--;){
		while((int)C[i].size() > n/2){
			ans += C[i].back();C[i].pop_back();
		}
	}
	cout<<ans<<'\n';
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	int T;cin>>T;while(T--)sol();
}

