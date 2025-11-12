#include<bits/stdc++.h>
#define int long long
const int Mo=998244353;
const int N =5E2+10;
using namespace std;
int n,m;
string s;
int c[N];
int jc(int x){
	int q=1;
	for(int i=x;i>=1;i--){
		q=(i*q%Mo)%Mo;
	}
	return q;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cout<<jc(n)/((jc(n-m)*jc(m))%Mo);//ÌØÊâÐÔÖÊa 
	return 0;
} 
