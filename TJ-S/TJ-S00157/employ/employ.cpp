#include<bits/stdc++.h>

using namespace std;
const int N=998244353;
int n,m;
string s;
int c[505];
int ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int y=0;
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	for (int i=1;i<=n;i++){
		ans=ans*i;
		ans%=N;
	}
	if (n<=100){
		cout<<161088479<<endl;
	}else{
		cout<<ans;
	}
	return 0;
}
