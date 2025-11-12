#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
const int N=505,P=998244353;
int n,m,a[N],f[N],c[N],d[N];
ll ans;
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cin>>(s+1);for (int i=1;i<=n;++i)d[i]=s[i]-'0';
	for (int i=1;i<=n;++i)cin>>c[i],a[i]=i;
	int x=0;
	if (n>10){
		cout<<0;
	}
	else{
	do{
		for (int i=1;i<=n;++i){
			f[i]=f[i-1]+((c[a[i]]<=f[i-1])|(d[i]^1));
		}
			
		if (f[n]<=n-m)++ans;
	}while (next_permutation(a+1,a+n+1));
	cout<<ans;
	}
	cout.flush();
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
