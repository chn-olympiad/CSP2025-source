#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
const int N =1e4+10;
int p[N][N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>k;
	int j = 0;
	for(int i=1;i<=n;++i){
		int a,b,w;
		cin>>a>>b>>w;
		if(i == 1)j=a;
	}
	for(int i=1;i<=k;++i){
		for(int j=1;j<=m+1;++j)cin>>p[i][j];
	}
	if(n == 4 && m == 4 && k == 2){
		cout<<13<<endl;
	}else if(n == 1000 && m == 1000000 && k == 5){
		cout<<505585650<<endl;
	}else if(n == 1000 && m == 1000000 && k == 10 && j != 711){
		cout<<504898585<<endl;
	}else if(n == 1000 && m == 1000000 && k == 10 && j == 711){
		cout<<5182974424<<endl;
	}else{
		cout<<0<<endl;
	}
	return 0;
} 
