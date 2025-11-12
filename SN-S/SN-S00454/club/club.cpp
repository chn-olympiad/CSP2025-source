//上午的哥们把极域退了让我没有文件，奇异搞笑 
#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace kong{bool st;}
namespace zhu{
int T,n,a[100100][5],zui[100100],ci[100100];
vector<int> b[5];
string main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		b[1].clear();
		b[2].clear();
		b[3].clear();
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int mx=max({a[i][1],a[i][2],a[i][3]});
			zui[i]=mx;
			ans+=mx;
			if(a[i][1]==mx){
				b[1].push_back(i);
				ci[i]=max({a[i][2],a[i][3]});
			}
			else if(a[i][2]==mx){
				b[2].push_back(i);
				ci[i]=max({a[i][1],a[i][3]});
			}
			else{
				b[3].push_back(i);
				ci[i]=max({a[i][1],a[i][2]});
			}
		}
		if(b[1].size()<b[2].size()) swap(b[1],b[2]);
		if(b[1].size()<b[3].size()) swap(b[1],b[3]);
		if((int)b[1].size()<=n/2){
			cout<<ans<<'\n';
			continue;
		}
		sort(b[1].begin(),b[1].end(),[=](int x,int y){
			return (zui[x]-ci[x])<(zui[y]-ci[y]);
		});
		for(int i=0;i<(int)b[1].size()-n/2;i++){
			ans-=zui[b[1][i]]-ci[b[1][i]];
		}
		cout<<ans<<'\n';
	}
	return "S组只是NOIP的试机赛！";
}
}
namespace kong{bool ed;double MB(){return (&st-&ed)/1048576.0;}}
signed main(){
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(0);
	cerr<<zhu::main()<<'\n'<<kong::MB();
	return 0;
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
