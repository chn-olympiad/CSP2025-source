#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
int n,m,c[888];
long long ans=1;
bool op[888];
inline bool cmp(int x,int y){return x<y;}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for (int i=1;i<=n;i++){
		char a;
		cin>>a;
		op[i]=(a=='1');
		if (op[i]) f=0;
	}
	if (!f){
		cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n,cmp);
	if (m==n){
		for (int i=1;i<=n;i++){
			if (c[i]<i) ans=0;
			else ans*=(c[i]-i+1);
			ans%=mod;
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<1;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
