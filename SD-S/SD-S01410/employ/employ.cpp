#include<bits/stdc++.h> 
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,a[N],cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0) cnt++;
	}
	long long sum1=0;
	for(int i=m;i<=cnt;i++){
		long long pre=1;
		for(int j=cnt;j>=(cnt-i+1);j--){
			pre=(pre*j)%mod;
		}
		sum1=(sum1+pre)%mod;
	}
	long long sum2=1;
	for(int i=1;i<=cnt-1;i++){
		sum2*=i;
	}
	cout<<(sum2*cnt*sum1)%mod;
	return 0;
}
//Ren5Jie4Di4Ling5%
