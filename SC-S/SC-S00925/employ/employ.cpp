#include<bits/stdc++.h>
using namespace std;
int n,m,zo;
long long s=1;
bool a[505];int p[505];
int mod=988244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	getchar();
	int flg=0,f1=0;
	for(int i=1;i<=n;i++){
		char k=getchar();
		a[i]=k-48;
		if(flg==0&&a[i]==1){
			f1=i;
			flg=1;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]<f1){
			zo++;
		}
	}
	s*=n-zo;
	for(int i=n-1;i>=1;--i){
		s=s*i%mod;
	}
	cout<<s;
	return 0;
}