#include<bits/stdc++.h>
using namespace std;

const int Mod=998244353;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int ans;
	int flag=1;
    vector<int> c(n);
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]==0) flag=0;
	}
	if((m!=1 && m!=n) or flag==1){
		ans=1;
	    int k=2;
        for(int i=0;i<n-m-1;i++){
		    ans=(ans*k)%Mod;
			k+=1;
     	}
	}
	else if(m==n){
		ans=0;
	}
	cout<<ans;
	return 0;
}