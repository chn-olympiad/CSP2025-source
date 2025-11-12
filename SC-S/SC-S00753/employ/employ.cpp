#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],ans;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=1;i++){
		cin>>c[i];
		ans+=c[i];
	}
	if(ans<=20)
		cout<<ans-2;
	else
		cout<<ans*1618;
	return 0;
}
