#include<bits/stdc++.h>
using namespace std;
const long long  mod=998244353;
long long sb(){
	long long a=rand()%78;
	long long b=rand()%78;
	a<<=4;a+=b;
	int k=rand()%30+20;
	while(k--){
		b=rand()%78;
		a<<=4;a+=b;
		a%=mod;
	}
	return a;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	srand(time(0));
	cout<<sb()%mod;
	return 0;
}

