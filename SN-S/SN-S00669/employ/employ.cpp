#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5;
string s1[N];
ll c[N];
void dfs(int i){
	dfs(i+1);
	cout<<i;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s1[i];
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=m;i++){
		dfs(1);
	}
}
//3 2
//101
//1 1 2

