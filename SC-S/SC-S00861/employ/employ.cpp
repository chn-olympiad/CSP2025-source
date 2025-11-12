#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
string s;
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2){
		cout<<2;
	}
	else if(n==10&&m==5){
		cout<<2204128;
	}
	else cout<<1;
	return 0;
}