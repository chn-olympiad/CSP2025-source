#include<bits/stdc++.h> 
using namespace std;
int n,a[5001],l,ml,m;
long long ans;
bool check(){
	if(l>2*ml&&m>=3)
		return 1;
	else
		return 0;
}
inline void p(int x){
	if(x==n+1)
		return;
	int old=0;
	if(a[x]>ml){
		old=ml;
		ml=a[x];
	}
	l+=a[x];
	m++;
	if(check()){
		ans++;
		ans%=998244353;
	}
	p(x+1);
	l-=a[x];
	m--;
	if(old)
		ml=old;
	p(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	p(1);
	printf("%d",ans%998244353);
	fclose(stdin);
	fclose(stdout);
}
