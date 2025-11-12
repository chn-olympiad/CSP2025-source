#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],f=0,ans=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=s.size();i++){
		if(s[i]!=1){
			f=1;
			break;
		}
	}
	if(f==0){
		for(int i=n;i>=0;i++){
			ans*=i;
		}
	}
	cout<<ans;
	return 0;
}