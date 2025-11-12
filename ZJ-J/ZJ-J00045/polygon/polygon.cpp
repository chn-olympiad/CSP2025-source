#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
const int M=998244353;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	unsigned long long n;
	cin>>n;
	unsigned long long sum=0;
	for(int i=3;i<=n;i++){
		unsigned long long cnt=1;
		for(int j=n;j>=n-i+1;j--){
			cnt=cnt*j;
		}
		for(int j=1;j<=i;j++){
			cnt/=j;
		}
		cnt%=M;
		sum+=cnt;
		sum%=M;
	}
	cout<<sum%M;
	return 0;
}
