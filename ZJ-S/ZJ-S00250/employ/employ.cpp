#include<bits/stdc++.h>
using namespace std;
int c[10000000];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	int ans=1;
	for(int i=n;i>0;i--){
		ans*=n;
	}
	cout<<ans<<endl;
	return 0;
} 
