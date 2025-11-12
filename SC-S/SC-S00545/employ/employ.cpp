#include<bits/stdc++.h>
using namespace std;
long long n,a=1,m,b[510],n1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n1>>m>>s;
	n1=n;
	for(int i=1;i<=n1;i++){
		cin>>a[i];
		if(a[i]==0){
			n--;
		}
	}
	if(n<m){
		cout<<0;
	}
	for(int i=1;i<=n1;i++){
		a*=i;
		a%=998244353;
	}
	cout<<a;
	return 0;
}