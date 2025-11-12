#include<bits/stdc++.h>
using namespace std;
int n,m=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=n;i>=2;i--){
		m*=i;
	}
	cout<<m;
	return 0;
}