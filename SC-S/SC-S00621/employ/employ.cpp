#include<bits/stdc++.h>
using namespace std;
int n,m,f,c[505];
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			f++;
		}
	}
	n-=f;
	long long p=1;
	for(int i=1;i<=n;i++){
		p*=i;
		p%=998244353;
	}
	cout<<p;
	
	return 0;
}