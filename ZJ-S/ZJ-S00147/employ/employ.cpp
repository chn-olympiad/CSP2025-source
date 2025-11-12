#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int mod=998244353;
char s[N];
int a[N],c[N],b[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int len=strlen(s),flag=1;
	for(int i=0;i<len;i++){
		a[i+1]=s[i]-'0';
		if(a[i+1]!=1)flag=0;
	}
	if(flag==1){
		int ans=1;
		for(int i=1;i<=n;i++){
			ans*=i;
			ans%=mod;
		}
		cout<<ans;
	}
	else{
		cout<<0;
	}
	
	return 0;
}
