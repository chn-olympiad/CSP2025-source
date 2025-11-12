#include<bits/stdc++.h>
using namespace std;
#define int long long
int fl=1,n,m,i;
int a[100100];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='0') a[i]=0,fl=0;
		else a[i]=1;
	}
	if(fl){
		cout<<0;
		return 0;
	}
	if(m==n){
		cout<<0;
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	return 0;
}
//CCFCCFCCFCCF
//保佑 保佑 保佑 保佑 保佑 保佑 保佑 保佑 保佑 保佑 
//last2min
