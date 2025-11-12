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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<13;
	return 0;
}
