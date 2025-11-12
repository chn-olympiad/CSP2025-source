#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	for(int i = 2;i<=m;i++){
		ans=ans*(m-i+2);
	}
	cout<<ans;
	return 0;
}
