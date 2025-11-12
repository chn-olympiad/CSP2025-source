#include<bits/stdc++.h>
using namespace std;
int c[510];
int const MOD=998244353;
int jisuan(int x){
	long long sum=1;
	for(long long i=x;i>=1;i--) sum=sum*i%MOD;
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int num=n;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		if(c[i]==0) num--;
	}
	int flag=true;
	for(int i=0;i<s.length();i++){
		if(s[i]!='1') flag=false;
	}
	long long xx=0;
	if(flag) {
		xx=jisuan(num-1)*num%MOD;
		long long i=n-num;
		i=i*jisuan(num-1)%MOD;
		if(num<m-1){
			cout<<0;
			return 0;
		}
		if(num==m-1) {
			cout<<i;
			return 0;
		}
		xx+=i;
		xx%=MOD;
		cout<<xx;
		return 0;
	}
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
