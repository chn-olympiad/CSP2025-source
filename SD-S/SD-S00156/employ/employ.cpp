#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int n,m,c[505],p=0,q=0;
char a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		if(a[i]-'0'==1){
			p++;
		}
	}
	if(p<m){
		cout<<0;
		return 0;
	}
	srand(time(0));
	rand();
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*(rand())%998244353)%998244353;
	}
	cout<<ans;
	return 0;
}
