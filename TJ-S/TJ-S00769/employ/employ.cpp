#include<bits/stdc++.h>
using namespace std;
const long long MOD=998244353;
const int N=510;
int n,m,cnt,a[N],giveup;
long long sum=1,ans=0;
string s;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	while(true){
		for(int i=n-m+1;i<=n;i++)
			sum=sum*i%MOD;
		ans=(ans+sum)%MOD;
		if(m==n)
			break;
		m++;
	}
	for(int i=1;i<=cnt;i++)
		sum=sum*i%MOD;
	cout<<sum<<'\n';
	return 0;
}
