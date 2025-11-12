#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n,m,di[512],now[512],c[512];
//next_permutation
void tmpread(){
	char tmp[512];
	scanf("%s",tmp);
	for(int i=0;i<n;i++)
		di[i]=tmp[i]=='0'?0:1;
}
long long int ans;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	tmpread();
	for(int i=0;i<n;i++)
		scanf("%d",c+i);
	for(int i=0;i<n;i++)
		now[i]=i;
	do{
//		for(int i=0;i<n;i++)
//			fprintf(stderr,"%d ",now[i]);
//		fprintf(stderr,"\n");
		//check
 		int fail=0,cnt=0,day=0;
		for(int i=0;i<n;i++,day++){
			if(di[day]==0 || fail>=c[i])
				fail++;
			else
				cnt++;
		}
//		printf("cnt==%d",cnt);
		if(cnt>=m){
			ans++;
//			printf("add");
			if(ans>=998244353)
				ans%=998244353;
		}
	}while(next_permutation(now,now+n));
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

