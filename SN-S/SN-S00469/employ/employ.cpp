//王培翔 SN-S00496 雁塔第一学校
#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[505];
string s;
long long f(int s){
	long long ans=1;
	while(s){
		ans*=s;
		ans%=998244353;
		s--;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	cout<<f(n);
	return 0;
}
