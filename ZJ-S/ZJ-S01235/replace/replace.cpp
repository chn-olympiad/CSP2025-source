#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int n,m;
string s1[201010],s2[201010],s3,s4,sum=0;
void bfs(string s){
	queue<string> q;
	q.push(s);
	while(!q.empty()){
		string c=q.front();
		q.pop();
		for(int i=1;i<=n;i++){
			int t=c.find(s1[1]);
			for(int j=0;j<t;j++){
				
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
	}
	for(int i=1;i<=m;i++){
		cin>>s3>>s4;
	}
	return 0;
}
