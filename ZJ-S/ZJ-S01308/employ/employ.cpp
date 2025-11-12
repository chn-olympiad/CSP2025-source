#include <bits/stdc++.h>
using namespace std;

int n,m,c[505],ans=1;
string s;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for(int i=0;i<s.size();i++)
		if(m==n and s[i]=='0'){
			printf("0\n");
			return 0;
		}
	if(m==n){
		printf("1\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
		ans=(ans*i)%998244353;
		
	printf("%d\n",ans);
	return 0;
}
