#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fir first
#define sec second
#define endl '\n'
const int N=1e6+5,M=5e3+5,INF=0x3f3f3f3f3f3f3f3f;

int n;
int a[N][3];
bool is[N];

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		int ed[3]={0,0,0},res=0;
		bool fl[3]={1,1,1};
		for(int i=1;i<=2;i++){
			vector<pair<int,int> > vec[3];
			for(int i=1;i<=n;i++){
				vec[0].push_back({a[i][0]-max(a[i][1],a[i][2]),i});
			}
			sort(vec[0].begin(),vec[0].end(),greater<pair<int,int> >());
			for(auto e:vec[0]){
				if(a[e.sec][0]>=a[e.sec][1] && a[e.sec][0]>=a[e.sec][2] && fl[0] && a[e.sec][0]!=-INF){
					ed[0]++;
					res+=a[e.sec][0];
//					cout << e.sec << '-' << 0 << endl;
					a[e.sec][0]=a[e.sec][1]=a[e.sec][2]=-INF;
				}
				else if(!fl[0]){
					a[e.sec][0]=-INF;
				}
				if(ed[0]>=n/2){
					fl[0]=0;
				}
			}
			for(int i=1;i<=n;i++){
				vec[1].push_back({a[i][1]-max(a[i][2],a[i][0]),i});
			}
			sort(vec[1].begin(),vec[1].end(),greater<pair<int,int> >());
			for(auto e:vec[1]){
				if(a[e.sec][1]>=a[e.sec][0] && a[e.sec][1]>=a[e.sec][2] && fl[1] && a[e.sec][1]!=-INF){
					ed[1]++;
					res+=a[e.sec][1];
//					cout << e.sec << '-' << 1 << endl;
					a[e.sec][0]=a[e.sec][1]=a[e.sec][2]=-INF;
				}
				else if(!fl[1]){
					a[e.sec][1]=-INF;
				}
				if(ed[1]>=n/2){
					fl[1]=0;
				}
			}
			for(int i=1;i<=n;i++){
				vec[2].push_back({a[i][2]-max(a[i][1],a[i][0]),i});
			}
			sort(vec[2].begin(),vec[2].end(),greater<pair<int,int> >());
//			ed=0;
			for(auto e:vec[2]){
				if(a[e.sec][2]>=a[e.sec][0] && a[e.sec][2]>=a[e.sec][1] && fl[2] && a[e.sec][2]!=-INF){
					ed[2]++;
					res+=a[e.sec][2];
//					cout << e.sec << '-' << 2 << endl;
					a[e.sec][0]=a[e.sec][1]=a[e.sec][2]=-INF;
				}else if(!fl[2]){
					a[e.sec][2]=-INF;
				}
				if(ed[2]>=n/2){
					fl[2]=0;
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}






//*Some strong music rings...
/*
Today is 20251101.
The code is by XYM!!! 

15:16 -- 100 pts

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
//We are strange to love.
//You know the rules and so do I~
//
//Never gonna give you up.
//Never gonna let you down.
//Never gonna run around and hurt you.
//Never gonna make you cry.
//Never gonna say goodbye.
//Never gonna run around and hurt you.
//
//luogu UID 1433474,luogu name Meng_Xiangyu
//I AKed CSP-J this morning. 
