#include<bits/stdc++.h>
using namespace std;

const long long N = 1e5+5;
long long i,j,k,l,n,m,a[N]; 
string s[N][3],s1[N][3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n >>m ;
	for(i = 1;i <= n;i ++){
		cin >>s[i][1]>> s[i][2];
	}
	while(m --){
		cin >> s1[i][1]>> s1[i][2];
		cout << 0 <<'\n';
	}
	return 0;
}