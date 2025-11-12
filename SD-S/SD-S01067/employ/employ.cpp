#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans=1,mod=998244353,res;
int n,m;
int a;
string s;

int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>s;
	
	for(int i=1;i<=n;i++){
		cin>>a;
		if(!a)
		  res++;
	}
	
	for(int i=1;i<=res;i++)
	  ans=ans*i%mod; 
	  
/*	if(res<m)
	  ans=0;*/  
	cout<<ans;
	
	return 0;
}
