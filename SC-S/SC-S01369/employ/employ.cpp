#include<bits/stdc++.h>
using namespace std;
const int N=505,MOD=998244353;
int n,m,ans,a[N],c[N];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>c[i],a[i]=i;
	do{
		int cnt0=0,cnt1=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'||cnt0>=c[a[i]])
				cnt0++;
			else
				cnt1++;
		}
		ans=(ans+(cnt1>=m))%MOD;
	}
	while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}