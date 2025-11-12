#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[526],ans;
char s[526];
namespace Ai_Sub1{
	const int mxs=1<<18;
	int S,f[mxs][19];
	void Solve(){
		S=1<<n;
		f[0][0]=1;
		for(int i=1,cc;i<S;i++){
			cc=0;
			for(int j=0;j<n;j++)
				if(i>>j&1)
					cc++;
			for(int k=0,ii;k<n;k++)
				if(i>>k&1){
					ii=i^(1<<k);
					if(s[cc]=='1'){
						for(int j=0;j<c[k+1]&&j<cc;j++)
							(f[i][cc-j]+=f[ii][cc-j-1])>=mod?f[i][cc-j]-=mod:0;
						for(int j=min(c[k+1],cc);j<=cc;j++)
							(f[i][cc-j]+=f[ii][cc-j])>=mod?f[i][cc-j]-=mod:0;
					}
					else
						for(int j=0;j<=cc;j++)
							(f[i][j]+=f[ii][j])>=mod?f[i][j]-=mod:0;
				}
		}
		printf("%d",f[S-1][m]);
		return ;
	}
}
namespace Ai_Sub2{
	const int mxs=1<<18;
	int S,f[mxs][19];
	void Solve(){
		S=1<<n;
		f[0][0]=1;
		for(int i=1,cc;i<S;i++){
			cc=0;
			for(int j=0;j<n;j++)
				if(i>>j&1)
					cc++;
			for(int k=0,ii;k<n;k++)
				if(i>>k&1){
					ii=i^(1<<k);
					if(s[cc]=='1'){
						for(int j=0;j<c[k+1]&&j<cc;j++)
							(f[i][cc-j]+=f[ii][cc-j-1])>=mod?f[i][cc-j]-=mod:0;
						for(int j=min(c[k+1],cc);j<=cc;j++)
							(f[i][cc-j]+=f[ii][cc-j])>=mod?f[i][cc-j]-=mod:0;
					}
					else
						for(int j=0;j<=cc;j++)
							(f[i][j]+=f[ii][j])>=mod?f[i][j]-=mod:0;
				}
		}
		printf("%d",f[S-1][m]);
		return ;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	if(n<=18)
		Ai_Sub1::Solve();
	else
		Ai_Sub2::Solve();
	return 0;
}
