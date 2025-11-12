#include<bits/stdc++.h>
#define int long long
#define Ms(shuzu,val) memset(shuzu,val,sizeof(shuzu))
#define Exit(str,val) {cout<<str<<endl;return val;}
using namespace std;
const int N=105;
int a[N];
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r0=a[1];
	sort(a+1,a+n*m+1,greater<int>());
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<" \n"[i==n*m];
	int pos=0;
	for(int i=1;i<=n*m;i++)
		if(a[i]==r0){pos=i;break;}
//	cout<<pos<<endl;
	int n0=pos%(2*n),m0=pos/(2*n)*2;
//	cout<<m0<<" "<<n0<<endl;
	if(n0==0) cout<<m0<<" "<<1<<endl;
	else if(n0<=n) cout<<m0+1<<" "<<n0<<endl;
	else cout<<m0+2<<" "<<2*n-n0+1<<endl;
	return 0;
}
/*
3 3
94 95 96 97 98 99 100 93 92
2 2
99 100 97 98
2 2
98 99 100 97




*/