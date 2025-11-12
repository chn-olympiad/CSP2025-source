#include<bits/stdc++.h>
using namespace std;
const int max_n=505,mod=998244353; 
int n,m,c[max_n],ans;
int p[11];
char s[max_n];
bool allone_A=true;
long long jiec_(int x){
	long long ans=1;
	for(int i=2;i<=x;i++){
		ans=(ans*i)%mod;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		do{
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='0'){
					cnt++;
				}
				else if(cnt>=c[p[i]]){
					cnt++;
				}
			}
			if(n-cnt>=m){
				ans=(ans+1)%mod;
			}
		}while(next_permutation(p+1,p+n+1));
	}
	else{
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				allone_A=false;
			}
		}
		if(allone_A){
			ans=jiec_(n);
		}
	}
	printf("%d\n",ans);
	return 0;
}
