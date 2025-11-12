#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1; 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		ans=ans*m;
		m-=1;
	}
	cout<<ans;
	return 0;
}
