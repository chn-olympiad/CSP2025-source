#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[505];
int c[505];
int dfs(int step,bool flag[],int a[]){
	if(step>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if((i-1-cnt)>=c[a[i]]){
				continue;
			}if(s[i]=='0'){
				continue;
			}cnt++;
		}return (cnt>=m);
	}else{
		int ret=0;
		for(int i=1;i<=n;i++){
			if(!flag[i]){
				flag[i]=1;
				a[step]=i;
				ret=(ret+dfs(step+1,flag,a))%998244353;
				flag[i]=0;
			}
		}return ret;
	}
}bool flag[505];
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	getchar();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}printf("%d\n",dfs(1,flag,a));
	return 0;
}
