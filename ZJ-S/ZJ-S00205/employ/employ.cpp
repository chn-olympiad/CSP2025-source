#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=505;
int n,m,k,tot;
string s;
int a[N],d[N];
vector<int>v;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=0;s[i]!='\0';i++)
		if(s[i]=='0') k++;
	m=n-m-k;
	if(m<0){
		printf("0");
	}else if(m-k>=0){
		int len=s.size();
		long long d=1;
		for(int i=1;i<=len;i++)
			d=d*i%MOD;
		printf("%lld",d);
	}else cout<<0;
	return 0;
}
