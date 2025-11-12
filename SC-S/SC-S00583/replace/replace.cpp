#include<bits/stdc++.h>
using namespace std;
const int N=2027;
int n,m,d[N],l[N];
char c[2][N][N],s[2][N];
unsigned long long b[N],h[2][N][N],f[2][N];
int main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&m),b[0]=1;
	for(int i=1;i<N;i++)b[i]=b[i-1]*2027;
	for(int i=0;i<n;i++){
		scanf("%s%s",c[0][i],c[1][i]),l[i]=strlen(c[0][i]),d[i]=l[i];
		for(int j=0;j<l[i];j++){
			if(c[0][i][j]!=c[1][i][j]){
				d[i]=j;
				break;
			}
		}
		for(int j=0;j<l[i];j++){
			h[0][i][j+1]=h[0][i][j]+c[0][i][j]*b[N-j-1];
			h[1][i][j+1]=h[1][i][j]+c[1][i][j]*b[N-j-1];
		}
	}
	for(int i=0;i<m;i++){
		scanf("%s%s",s[0],s[1]);
		if(strlen(s[0])!=strlen(s[1])){
			printf("0\n");
			continue;
		}
		int k=0,ans=0,len=strlen(s[0]);
		for(int j=0;j<len;j++){
			if(s[0][j]!=s[1][j]){
				k=j;
				break;
			}
		}
		for(int j=0;j<len;j++){
			f[0][j+1]=f[0][j]+s[0][j]*b[N-j-1];
			f[1][j+1]=f[1][j]+s[1][j]*b[N-j-1];
		}
		for(int j=0;j<n;j++){
			if(d[j]==l[j])continue;
			int t=k-d[j];
			if(t<0)continue;
			if((h[0][j][l[j]]-h[0][j][0])*b[0]==(f[0][t+l[j]]-f[0][t])*b[t]
			 &&(h[1][j][l[j]]-h[1][j][0])*b[0]==(f[1][t+l[j]]-f[1][t])*b[t]
			 &&(f[0][t]-f[0][0])*b[0]==(f[1][t]-f[1][0])*b[0]
			 &&(f[0][len]-f[0][t+l[j]])*b[t+l[j]]==(f[1][len]-f[1][t+l[j]])*b[t+l[j]])ans++;
//			else if(j==1)printf("%d:%d\n",t,
//			(h[0][j][l[j]]-h[0][j][0])*b[0]==(f[0][t+l[j]]-f[0][t])*b[t]);
		}
		printf("%d\n",ans);
	}
	fclose(stdin),fclose(stdout);
	return 0;
}