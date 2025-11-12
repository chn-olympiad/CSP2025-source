#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	long long a=0;
	for(int i=0;i<n;i++){
	    if(s[i]=='1'){
	    a++;	
		}
	}
	if(a<m or n<m){
		cout<<0;
		return 0;
	}
	else{
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
		}
		cout<<ans;
	}
	return 0;
}


