#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define For(a,b,c) for(int a=b;a<=c;++a)
//#define froepen freopen
using namespace std;
const int N=1e5+4;
vector<int>v[3];
int a[3][N]; bool mak[N];
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T; for(cin>>T;T--;){

	v[0].clear();v[1].clear();v[2].clear(); memset(mak,0,sizeof mak);
	int n; cin>>n;
	For(i,1,n){
		cin>>a[0][i]>>a[1][i]>>a[2][i];
		if(a[0][i]>=a[1][i]&&a[0][i]>=a[2][i])		v[0].push_back(i);
		else if(a[1][i]>=a[0][i]&&a[1][i]>=a[2][i])	v[1].push_back(i);
		else if(a[2][i]>=a[0][i]&&a[2][i]>=a[1][i])	v[2].push_back(i);
	}
	int fl=114514,a1=-1,a2=-1;
//	for(int x:v[0]) cout<<x<<" "; cout<<"\n";
//	for(int x:v[1]) cout<<x<<" "; cout<<"\n";
//	for(int x:v[2]) cout<<x<<" "; cout<<"\n";
	if((int)v[0].size()>n/2)fl=0; if((int)v[1].size()>n/2)fl=1; if((int)v[2].size()>n/2)fl=2;
	if(fl==114514){
		int ans=0;
		for(int x:v[0]) ans+=a[0][x];for(int x:v[1]) ans+=a[1][x];for(int x:v[2]) ans+=a[2][x];
		cout<<ans<<"\n"; continue;
	}if(fl==0) a1=1,a2=2; if(fl==1) a1=0,a2=2; if(fl==2) a1=0,a2=1;
	sort(v[fl].begin(),v[fl].end(),[&](int x,int y){
		return min(a[fl][x]-a[a1][x],a[fl][x]-a[a2][x])<min(a[fl][y]-a[a1][y],a[fl][y]-a[a2][y]);
	});
	int cnt=(int)v[fl].size()-n/2,ans=0;
//	fprintf(stderr,"[%d %d %d]\n",fl,a1,a2);
//	for(int x:v[1]) cout<<x<<" "; cout<<"\n";
	For(i,0,cnt-1)
		ans+=max(a[a1][v[fl][i]],a[a2][v[fl][i]]),mak[v[fl][i]]=1;
	For(i,1,n) if(!mak[i]) ans+=max(a[0][i],max(a[1][i],a[2][i]));
	cout<<ans<<"\n";

	}
}
/*
3

4
4 2 1
3 2 4
5 3 4
3 5 1

4
0 1 0
0 1 0
0 2 0
0 2 0

2
10 9 8
4 0 0
*/
