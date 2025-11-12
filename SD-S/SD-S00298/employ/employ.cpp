#include<iostream>
#include<cstdio>
using namespace std;
const int N=600,p=998244353;
int n,m;
int c[N];
int f[262200][22];
char s[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d %s",&n,&m,s);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++) if((1<<j)&i) cnt++;
		for(int j=0;j<=cnt;j++){
//			cout<<i<<" "<<j<<"          "<<f[i][j]<<endl;
			for(int k=0;k<n;k++){
				if(((1<<k)&i)==0){
					if(s[cnt]=='0'){
						f[i|(1<<k)][j]+=f[i][j];
						f[i|(1<<k)][j]%=p;
					}
					else{
						if(cnt-j>=c[k+1]){
							f[i|(1<<k)][j]+=f[i][j];
							f[i|(1<<k)][j]%=p;
						}
						else{
							f[i|(1<<k)][j+1]+=f[i][j];
							f[i|(1<<k)][j+1]%=p;
						}
					}
				}
			}
		}
	}
	int ans=0;
	for(int i=m;i<=n;i++) ans+=f[(1<<n)-1][i],ans%=p;
	printf("%d",ans);
	return 0;
}
