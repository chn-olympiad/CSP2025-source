#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
ll n,m;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	srand(time(NULL));
	for(int i=1;i<=m;i++) printf("%lld\n",rand()%min(n,m));
	return 0;
}
