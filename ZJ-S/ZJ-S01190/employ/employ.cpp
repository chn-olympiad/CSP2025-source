#include <bits/stdc++.h>
#define ll long long
#define sc scanf
#define pr printf
#define v1 first
#define v2 second
#define IINF 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=505;
char s[N];
int c[N];
int p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	sc("%d%d",&n,&m);
	sc("%s",s+1);
	for(int i=1; i <= n; i++)sc("%d",&c[i]);
	for(int i=1; i <= n; i++)p[i]=i;
	ll ans=0;
	do{
		int cnt=0;
		for(int i=1; i <= n; i++){
			if(cnt>=c[p[i]]){
				cnt++;
				continue;
			}
			if(!(s[i]-'0')){
				cnt++;
				continue;
			}
		}
		if(m+cnt<=n)ans++;
	}while(next_permutation(p+1,p+n+1));
	cout <<ans;
	return 0;
}