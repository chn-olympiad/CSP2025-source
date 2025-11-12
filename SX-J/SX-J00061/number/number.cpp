#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long s;
    cin>>s;
    long p=s%10;
    long o=s/10%10;
	long i=s/100%10;
	long u=s/1000%10;
	long j=s/10000%10;
	long y=s/100000%10;
	long t=s/1000000%10;
	long r=s/10000000%10;
	if(s>p*1+o*10+i*10+u*10+j*10+y*10+t*10+r*10) cout<<s;
    else cout<<p<<o<<i<<u<<j<<y<<t<<r;
	return 0;
}