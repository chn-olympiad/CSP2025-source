#include<bits/stdc++.h>
using namespace std;
const int N=5e2+5;
const int mod=998244353;
int n,m,s[N],c[N],p=1;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s1;
	cin>>s1;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<s1.size();i++) s[i]=s1[i]-48;
	for(int i=0;i<m;i++){
		p*=n%mod;
		n--;
	}
	cout<<p;
	return 0;
}