#include<bits/stdc++.h>
using namespace std;	
int c[510];string s;int n,m,tr,fa,rs;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	rs=n;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]==0){
			fa++;
		}else{
			tr++;
		}
	}
	
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			rs--;
		}
	}
	if(tr=s.size()){
		cout<<((n+n-m)*m/2)%998244353;
	}else{
		cout<<((n+n)*m/2)%998244353;
	}
	return 0;
}
