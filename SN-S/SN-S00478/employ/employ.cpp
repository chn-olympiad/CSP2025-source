#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100050];
char c[100050];
unsigned long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>c;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=n;i>=m;i--){
		ans*=i;
		ans%=998244353;
	}
	printf("%lld",(ans%998244353));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
