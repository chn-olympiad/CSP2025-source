#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=505;
int c[M],a[M];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	if(n==m){
		printf("0");
		return 0;
	}
	string s;
	getline(cin,s);	
	getline(cin,s);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]),a[i]=i;
	do{
		int fail=0,now=0;
		for(int i=1;i<=n;i++){
			if(fail>=c[a[i]]){
				fail++;
				continue;
			}else {
				if(s[i-1]=='0')fail++;
				else now++;
			}
		}
		ans+=(now>=m);
	}while(next_permutation(a+1,a+1+n));
	printf("%d",ans);
	return 0;
}