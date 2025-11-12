#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int b_1[N]={},b_2[N]={},b_3[N]={};
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n;
	cin>>n;
	string s,u;
	cin>>s;
	getline(u);
	cout<<n*(n-1)*(n-2)%998244353;
	return 0;
}
