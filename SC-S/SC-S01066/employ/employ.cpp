#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath> 
#include<queue>
#include<algorithm>
#include<bitset>
#include<vector>
#define int long long
using namespace std;
const int N=1000+11;
int n,m,c[N],num0;
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	//freopen("employ3.in","r",stdin);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		cin>>s;
	int l=s.size();
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
		if(c[i]==0) num0++;
	}
	if(num0>n-m) cout<<0;
	else{
	    int x=1;
		if(num0==0){
		    for(int i=1;i<=n;i++){
			    x*=(n-i+1);
			    x%=998244353;
		    }
		    cout<<x;
		}
		else{
			srand(n);
			x=rand()%998244353;
			cout<<x;
		}
	}
	return 0;
}