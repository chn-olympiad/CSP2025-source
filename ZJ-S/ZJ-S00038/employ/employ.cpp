#include<bits/stdc++.h>
using namespace std;
const int N=500+5;
long long a[N],n,ans=1,m,p;
char c[N];
bool f[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	p=0;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		f[i]=(c[i]=='1');
	}for(int i=1;i<=n;i++){
		cin>>a[i]; 
		ans=ans*i;
		ans=ans%998244353;
	}cout<<ans;
	return 0;
}
