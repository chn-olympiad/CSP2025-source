#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[1005],c[1005];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=true;
	/*
	for(int i=1; i<=n; i++){
		int maka=0;
		do{
			maka++;
			c[maka]=getchar();
			if(c[maka]=='0') flag=false;
		}while(c[maka]!='\n');
	}
	*/
	int fail=0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]==0) fail++;
	}
	long long ans=1;
	for(int i=1; i<=n-fail; i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans<<endl;
	return 0;
} 
