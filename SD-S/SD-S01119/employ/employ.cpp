#include<bits/stdc++.h>
const int N=510;
const int P=998244353;
using namespace std;
typedef long long ll;
int n,m;
int c[N],a[N];
bool b[N];
char st[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf(" %s",st+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
		b[i]=st[i]-'0';
		a[i]=i;
	}
	bool flag=1;
	int ans=0;
	while(flag){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!b[i]||cnt>=c[a[i]])cnt++;
		}
		if(n-cnt>=m)ans++;
		flag=next_permutation(a+1,a+n+1);
	}
	printf("%d",ans);
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
