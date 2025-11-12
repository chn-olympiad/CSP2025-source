#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int _MAXn=15;

int n,m;
int dif[_MAXn];
int pes[_MAXn];
int pem[_MAXn];
ll ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%1d",&dif[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&pes[i]);
	}
	for(int i=1;i<=n;i++){
		pem[i]=i;
	}
	do{
		int cnt=0,fail=0;
		for(int i=1;i<=n;i++){
			if(fail>=pes[pem[i]])fail++;
			else if(!dif[i])fail++;
			else cnt++;
		}
		if(cnt>=m)ans++;
	}while(next_permutation(pem+1,pem+n+1));
	printf("%d\n",ans);
	return 0;
}

