#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int mod=998244353;
const int N=505;
string s;
int c[N];
int sum1,sum2;
int jie(int x){
	int ans=1;
	for(int i=2;i<=x;i++) ans*=i;
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n;
	cin>>m>>s;
	for(int i=1;i<=n;i++)
	cin>>c[i];
	for(int i=1;i<=n;i++){
		if(sum1>=c[i]) sum1++;
		else sum2++;
	}
	cout<<jie(n);
	return 0;
}
