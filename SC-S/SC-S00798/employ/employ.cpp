#include<bits/stdc++.h>
using namespace std;
const long long inf=998244353;
int n,m;string a;int b[1010];
void aa(){
	long long num=0,u=1,v;
	for(int i=1;i<=n;i++){
		u*=i;
		u%=inf;
		if(i==n-m){
			v=u;
		}
	}
	if(n==m){
		printf("%lld",u);
		return;
	}
	printf("%lld",u/v%inf);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>a;
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	aa();
	return 0;
} 