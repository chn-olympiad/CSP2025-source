#include<bits/stdc++.h>
using namespace std;
const int MAXN=1145/2;
int n,m,patience[MAXN],f[MAXN][MAXN],f2[MAXN][MAXN],lst[MAXN],ptf[MAXN],ans=0;
char lstc[MAXN];
int main(){
	freopen("employ.in","r+",stdin);
	freopen("employ.out","w+",stdout);
	cin>>n>>m;
	cin>>(lstc+1);
	for(int i=1;i<=n;i++){
		int save;cin>>save;
		patience[save]++;
	}
	ptf[0]=patience[0];
	for(int i=1;i<=n;i++){
		ptf[i]+=(patience[i]+ptf[i-1]);
	}
	for(int i=1;i<=n;i++){
		lst[i]=lstc[i]-'0';
	}
	if(lst[1]=1){
		f[1][0]+=n-patience[0];
		f[0][1]+=patience[0];
	}
	for(int i=2;i<=n;i++){
		if(lst[i]==1){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(k>0){
						if(ptf[k-1]>k-1) f2[j][k]+=f[j][k-1]*(ptf[k-1]-k+1);
					}
					if(j>0){
						if(ptf[n]-ptf[k-1]>0){
							f2[j][k]+=f[j-1][k]*(ptf[n]-ptf[k-1]);
							if(ptf[n]-ptf[k-1]<j-1){
								f2[j-1][k+1]+=f[j-1][k]*(j-1-(ptf[n]-ptf[k-1]));
							}
						}
					}
				}
			}
		}
		else{
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(k>0){
						f2[j][k]=f[j][k-1]*(n-(j+k-1));
					}
				}
			}
		}
		for(int j=0;j<=n;j++){
			for(int k=0;k<=n;k++){
				f[j][k]=f2[j][k];
			}
		}
	}
	for(int i=m;i<=n;i++){
		ans+=f2[i][n-i];
	}
	cout<<ans;
}
