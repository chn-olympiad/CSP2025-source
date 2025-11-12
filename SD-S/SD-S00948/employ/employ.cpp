#include <bits/stdc++.h>
using namespace std;
int n,m,ans=1,x;
char s[2000010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0'){
			flag=1;
		}
	}
	if(flag==0){
		for(int i=1;i<=n;i++){
			cin>>x;
			ans+=x;
		}
	}
	cout<<ans%998244353;
	return 0;
}
