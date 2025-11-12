#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[505],c[505];
void files(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return;
}
int A(int p){
	int ans=1;
	for(int i=1;i<=p;i++){
		ans=ans*i%mod;
	}
	return ans;
}

void pM(){
	if(s[0]==1){
		cout<<A(n);
		return;
	}
}

int main(){
	files();
	cin>>n>>m;
	cin>>s;
	bool pA=true;
	for(int i=0,j=1;i<s.size();i++,j++){
		a[j]=s[i]-'0';
		if(a[j]==0)pA=false;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	
	if(pA){
		cout<<n;return 0;
	}
	
	if(m==1){
		pM();return 0;
	}
	
	if(m==n){
		cout<<0;
		return 0;
	}
	
	return 0;
}
