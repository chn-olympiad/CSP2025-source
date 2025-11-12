#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int mod=998244353;
int n,m,cnt;
string s;
int c[505];
long long cheng(int cnt){
	long long fac=1;
	for(int i=1;i<=cnt;i++){
		fac*=i;
		fac%=mod;
	}
	return fac;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]) cnt++;
	}
	cout<<cheng(cnt);
	return 0;
} 
