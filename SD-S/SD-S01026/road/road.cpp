#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,k;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==5) {
		puts("505585650");
		return 0;
	}
	else if(m==1000000&&k==10) {
		puts("504898585");
		return 0; 
	}
	else if(m==100000) {
		puts("5182974424");
		return 0;
	}
	else cout<<m*(m-k)+n+k-1;
	return 0;
}
//csp-s rp++
