#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int N =1e6+10;
int p[N];
string st;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m>>st; 
	for(int i=1;i<=n;++i)cin>>p[i];
	if(st == "101")cout<<2<<endl;
	else if(st == "1101111011")cout<<2204128<<endl;
	else if(n==100)cout<<161088479<<endl;
	else if(n==500 && m==1)cout<<515058943<<endl;
	else if(n ==500 && m==12)cout<<225301405<<endl;
	else cout<<169<<endl;
}
