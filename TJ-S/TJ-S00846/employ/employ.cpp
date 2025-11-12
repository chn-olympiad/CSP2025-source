#include<bits/stdc++.h>
using namespace std;
int c[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}int ans;
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			ans*=c[i];
		}
	}cout<<ans;
	return 0;
}

