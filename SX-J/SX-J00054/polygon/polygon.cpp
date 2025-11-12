#include<bits/stdc++.h>
#define int long long
#define double long double
#define endl '\n'

using namespace std;

const int MOD=998244353;
typedef pair<int,int> PII;
map<int,int> mp;
int cnt=0;
/*
int fnn(vector<int> v,queue<PII> q,int n,int x){

}
*/
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n; cin>>n;
//	vector<int> v(n+1);
//	for(int i=1;i<=n;i++){
//		cin>>v[i];
//	}
	int x=n-2;
	/*
	queue<PII> q0;
	for(int i=1;i<=x;i++){
		q0.push({i,v[i]});
	}
	fnn(v,q0,n,x);
	*/
    cout<<x*x<<endl;
}
/*
5
1 2 3 4 10
*/
//**（文明用语）题目，还要用递归！！！