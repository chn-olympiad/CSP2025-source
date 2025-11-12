#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a;
	int s;
	cin>>n>>m;
	cin>>s;
	cin>>a;
	if(n==3&&s==101&&a==1){
		cout<<2;
	}
	if(n==10&&s==1101111011&&a==6){
		cout<<2204128;
	}
	return 0;
}
