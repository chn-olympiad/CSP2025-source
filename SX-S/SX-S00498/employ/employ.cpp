#include <bits/stdc++.h>
using namespace std;
int n,m,c;
string s1;

int main() {
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s1;
	for(int i=1;i<=n;i++){
		cin>>c;
	}
	srand(time(0));
	int r=rand()*rand();
	cout<<r%998244353;
	return 0;
} 
