#include<bits/stdc++.h>
#define ll long long
#define sdn cout
#define pb push_back
using namespace std;
const int N = 2e5 + 10,INF = 1e9 + 7;
int T,n,a[N][5],cnt,cha[N];
ll sm;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);sm = 0;cnt = 0;
		int n1=0,n2=0,n3=0,opt = 0;
		for(int i = 1;i <= n;i ++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			int k = max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][3]==k)  n3 ++;
			if(a[i][2]==k)  n2 ++;
			if(a[i][1]==k)  n1 ++;
			sm += k;
		}
		int k = max(n1,max(n2,n3));
		if(n1==k)  opt = 1;
		if(n2==k)  opt = 2;
		if(n3==k)  opt = 3;
		if(k > n/2){
			for(int i = 1;i <= n;i ++){
				int mx = max(a[i][1],max(a[i][2],a[i][3]));
				if(mx == a[i][opt]){
					sort(a[i]+1,a[i]+4);
					cha[++cnt] = a[i][3]-a[i][2];
				}
			}
			sort(cha+1,cha+cnt+1);
			int x = cnt-n/2;
			for(int i = 1;i <= x;i ++)  sm -= cha[i];
		}
		printf("%lld\n",sm);
	}
	return 0;
}
/*
first,min is not used.
what's the right way to find£¿
zhen neng tanxin ma?\\???//
make a3-2 zuixiao is ok.
14:58 guoyangli
*/
