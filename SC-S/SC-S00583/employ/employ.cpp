#include<bits/stdc++.h>
using namespace std;
const long long Q=998244353;
int n,m,c[22],cnt[1<<18],ans,f[22][1<<18];
char s[22];
int main(){
	freopen("employ.in","r",stdin),freopen("employ.out","w",stdout);
	scanf("%d%d%s",&n,&m,s);
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	for(int i=1;i<(1<<n);i++)cnt[i]=cnt[i>>1]+(i&1);
	f[0][0]=1;
	for(int j=0;j<=n;j++){
		for(int i=1;i<(1<<n);i++){
			if(cnt[i]<j)continue;
			for(int k=0;k<n;k++){
				if((i>>k)&1){
//					if(i==1&&j==0&&k==0)printf("%d,%d\n",s[cnt[i]-1]-'0',c[k]>j);
					if(s[cnt[i]-1]-'0'&&c[k]>j)f[j][i]=(f[j][i]+f[j][i&(~(1<<k))])%Q;
					else if(j&&(s[cnt[i]-1]=='0'||c[k]<=j-1)){
						f[j][i]=(f[j][i]+f[j-1][i&(~(1<<k))])%Q;
					}
				}
			}
//			printf("f[%d][%d]=%d\n",i,j,f[i][j]);
		}
	}
	for(int i=0;i<=n-m;i++)ans=(ans+f[i][(1<<n)-1])%Q;
	printf("%d\n",ans);
	fclose(stdin),fclose(stdout);
	return 0;
}