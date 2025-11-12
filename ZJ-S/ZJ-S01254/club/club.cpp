#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define pi pair<int,int>
using namespace std;
const int N=1e5+5;
int a[N][5];
int er[N];
int zz[N];
int n;
priority_queue<pi,vector<pi>,greater<pi>>q1,q2,q3;
void solve(){
	while(!q1.empty()) q1.pop();
	while(!q2.empty()) q2.pop();
	while(!q3.empty()) q3.pop();
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		int maxx=0,ip;
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(maxx<a[i][j]){
				ip=j;
			}
			maxx=max(maxx,a[i][j]);
		}
		ans+=maxx;
		int fs=0;
		int cz=0x3f3f3f3f;
		for(int j=1;j<=3;j++){
			if(ip!=j){
				if(cz>a[i][ip]-a[i][j]){
					cz=a[i][ip]-a[i][j];
					fs=i;
				}
			}
		}	
		er[i]=fs;
		zz[i]=cz;
		if(ip==1){
			q1.push({cz,i});
		}	
		if(ip==2){
			q2.push({cz,i});
		}	
		if(ip==3){
			q3.push({cz,i});
		}				
	}
//	cout<<q1.size()<<' '<<q2.size()<<' '<<q3.size()<<endl;
/*	while(!q1.empty()){
		cout<<q1.top().first<<' ';
		q1.pop();
	}
	cout<<endl;*/
	while(int(q1.size())>n/2){
		ans-=q1.top().first;
		q1.pop();
	}
	while(int(q2.size())>n/2){
		ans-=q2.top().first;
		q2.pop();
	}
	while(int(q3.size())>n/2){
		ans-=q3.top().first;
		q3.pop();
	}	
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
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