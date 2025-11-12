#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
char c[510];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,c);
	int k=0;
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);
		if(x>0)
			k++;
	}
	int ans=1;
	while(m--){
		ans*=k;
		ans%=998244353;
		k--;
	}
	printf("%d",ans);
	return 0;
}