#include<bits/stdc++.h>
using namespace std;
const int Md=998244353;
int n,m,c[501],ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=n;i>=1;i--){
		ans=ans*i%Md;
	}
	cout<<ans;
	return 0;
}
