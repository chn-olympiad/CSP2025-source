#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt=0,sum=0,c[510];
char s[510];
bool used[510];
void search(long long k){
	for(long long i=1;i<=n;i++)
		if(!used[i]){
			bool flag=false;
			used[i]=true;
			if(!(s[k]^'0')||sum>=c[i])
				sum++,flag=true;
			if(!(k^n)){
				if(n-sum>=m)
					cnt++;
			}
			else
				search(k+1);
			used[i]=false;
			if(flag)
				sum--;
		}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld\n%s",&n,&m,s+1);
	for(long long i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	search(1);
	printf("%lld",cnt%998244353);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
