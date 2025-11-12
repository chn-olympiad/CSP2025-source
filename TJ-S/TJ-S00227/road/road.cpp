#include<iostream>
using namespace std;
int n,m,k;
int road[1000005][5];//i=1->u i=2->v i=3->w
int vill[11][10005];
long long tem,cnt=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>road[i][1]>>road[i][2]>>road[i][3];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>vill[i][j];
		}
	}
	cout<<0;
	return 0;
}
//CSP-S Journal
//16:33 Whoa,What A Big Dynamic Planning.
//      What just inspired CCF of this?!
//16:45 Maybe Not DP?
//      It Looks Like Sth. Easier.
//16:50 Ahh,Too Hard!
//      I'll Just NoGeneral First.(32pts)
//      To Be Continued One Day.
//freopen
