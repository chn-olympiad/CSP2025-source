#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500],cnt;
string s;
long long check(long long x){
	long long num=1;
	for(int i=1;i<=x;i++){
		num*=i;
	}
	return num;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt==n){
		cnt=0;
		for(int i=m;i<=n;i++){
			cnt=cnt+check(n)/check(n-i);
		}
		cout<<cnt%998244353;
	}
	return 0;
}
