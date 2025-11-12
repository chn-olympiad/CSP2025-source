#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=505;
const long long md=998244353;
bool ud[N],lv[N],flg;
int bk[N],n,c[N],m;
long long ans;
void chk(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt>=c[bk[i]]){
			cnt++;
			continue;
		}
		if(!lv[i]){
			cnt++;
			continue;
		}
	}
	if(n-cnt>=m)ans=(ans+1)%md;
}
void dfs(int x){
	if(x>n){
		chk();
		return ;
	} 
	for(int i=1;i<=n;i++){
		if(ud[i])continue;
		ud[i]=1;
		bk[x]=i;
		dfs(x+1);
		ud[i]=0;
	}
}
void work1(){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(c[i]==0)cnt++;
	}
	if(n-cnt>=m){
		long long jc=1;
		for(int i=1;i<=n;i++)
			jc=(jc*i)%md;
		printf("%lld",&jc);
	}else printf("0");
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		char ch='a';
		while(ch!='1'&&ch!='0')scanf("%c",&ch);
		lv[i]=ch-'0';
		if(!lv[i])flg=0;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(flg){
		work1();
		return 0;
	}
	
	dfs(1);
	printf("%lld",ans);
	return 0;
}
/*
6 5
111111
3 4 2 2 4 0
*/
