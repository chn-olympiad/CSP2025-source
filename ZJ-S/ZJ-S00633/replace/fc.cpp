#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+1e1;
int ans[N],n=27578;
signed main()
{
 freopen("replace.out","r",stdin);
 for(int i=1;i<=n;i++)
 	scanf("%lld",&ans[i]);
 fclose(stdin);
 freopen("replace3.ans","r",stdin);
 for(int i=1;i<=n;i++)
 {
 	int x;
 	scanf("%lld",&x);
 	if(x!=ans[i])
 	{
 		printf("Wrong!\n");
 		printf("%lld %lld %lld\n",i,x,ans[i]);
 		return 0;
	}
 }
 printf("Accept!\n");
 return 0;
}
