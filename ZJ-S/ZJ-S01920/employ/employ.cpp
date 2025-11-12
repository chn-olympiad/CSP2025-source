#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int c[510];
int main(){
	frepoen("employ.in","r",stdin);
	frepoen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		if(c[i]==0){
			printf("0\n");
			exit(0);
		}
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			printf("0\n");
			exit(0);
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=1ll*ans*i%MOD;
	}
	printf("%d\n",ans);
	return 0;
}
