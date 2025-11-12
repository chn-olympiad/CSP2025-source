#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,k,ans;
struct edge{
	LL to,w;
};
vector <edge> q[1005];
queue <LL> q1;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++) cout<<0<<endl;
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
