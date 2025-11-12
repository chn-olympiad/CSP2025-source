#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=998244353;
int n,m;
string s;
int c[510];
int A(int n,int m){
	int sum=1;
	for(int i=n;i>=n-m+1;i--){
		sum*=i;
		sum%=M;
	}
	return sum;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int shiji=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			shiji--;
		}
	}
	if(shiji>=m){
		cout<<A(n,shiji)%M;
	}
	else{
		cout<<0;
	}
	return 0;
} 