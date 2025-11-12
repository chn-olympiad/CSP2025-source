#include<bits/stdc++.h>
#define LANH using
#define AK namespace
#define CSPS std
LANH AK CSPS;
typedef long long ll;
int n,m;
string s;
int c[509];
ll res;
ll mod=998244353;
ll zerps;
bool f;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	res=1;
	for(int i=1;i<=n;i++){
		res*=i;
		res%=mod;
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i-1]=='0'){
			f=1;
			break;
		}
	}
	if(!f){
		sort(c+1,c+1+n);
		for(int i=1,x;i<=n;i++){
			if(c[i])x=i;
			if(c[i])res*=(n-x+c[i]-1);
			res%=mod;
		}
		cout<<res;
		return 0;
	}
	if(n==m){
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||!c[i]){
				cout<<0;
				return 0;
			}
		}
		cout<<res;
		return 0;
	}
	cout<<res; 
	return 0;

}

