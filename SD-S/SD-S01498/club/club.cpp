//by OldDriverTree
#include<bits/stdc++.h>
#define range(vec) vec.begin(),vec.end()
#define tup array<int,3>
#define P pair<int,int>
#define int long long
#define mid (l+r>>1)
using namespace std;
const int N=1e5+1;
int T,n,ans,tax[3];
vector<int> qaq;
P a[N][3];

int read() {
	int x=0; bool f=true; char c=0;
	while (!isdigit(c) ) f&=(c!='-'),c=getchar();
	while (isdigit(c) ) x=x*10+(c&15),c=getchar();
	return f?x:-x;
}
main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while (T--)
	{
		n=read(),ans=0;
		memset(tax,0,sizeof tax);
		for (int i=0;i<n;i++) {
			for (int j=0;j<3;j++) a[i][j]={read(),j};
			sort(a[i],a[i]+3,greater<P>() );
			ans+=a[i][0].first,tax[a[i][0].second]++; 
		}
		int p=max_element(tax,tax+3)-tax;
		if (tax[p]>n/2) {
			for (int i=0;i<n;i++) if (a[i][0].second==p)
			qaq.push_back(a[i][0].first-a[i][1].first);
			sort(qaq.begin(),qaq.end() );
			for (int i=0;i<tax[p]-n/2;i++) ans-=qaq[i];
			qaq.clear();
		}
		printf("%lld\n",ans);
	}
	return 0;
}
/*
会赢吗 
笑点解析：不登校  
怎么放了《泪的告白》 
如果没有限制，每个人显然选最大值
如果有限制，每个人显然都不会选最小值 
我们一开始让所有人选最大值，如果有大于 n/2的，让他改为次大值，取前 k 小即可 
在 15:06 过掉了所有大样例  
*/
