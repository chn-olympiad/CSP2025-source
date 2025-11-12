#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m,sum,c[505];
long long ans=1;
string s;
bool f=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int k=0;
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
		if(c[i]==0) k++;
		if(s[i-1]=='0') f=false;
		sum+=s[i-1]-'0';
	}
	if(f){
		for(int i=1;i<=n-k;i++){
			ans=(ans*i)%MOD;
		}
		printf("%lld",ans);
	}
	if(sum<m||n-k<m) printf("0");
	return 0;
}
