#include <bits/stdc++.h>
using namespace std;
const int P=998244353;
int n,m,f[1<<18][19],pp[1<<18],a[18];
bool ok[18];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char c;
		cin>>c;
		ok[i]=c-'0';
	}
	for(int i=1;i<(1<<n);i++)
		pp[i]=pp[i>>1]+(i&1);
	for(int i=0;i<n;i++) cin>>a[i];
	f[0][0]=1;
	for(int i=1;i<(1<<n);i++)
		for(int j=0;j<=pp[i];j++){
			for(int k=0;k<n;k++)
				if((i>>k)&1){
					int t=(i^(1<<k));
					if(ok[pp[i]-1]){
						if(a[k]<=pp[i]-j-1){
							f[i][j]+=f[t][j];
							if(f[i][j]>=P) f[i][j]-=P;
						}
						if(pp[i]-j<a[k]){
							if(j) f[i][j]+=f[t][j-1];
							if(f[i][j]>=P) f[i][j]-=P;
						}
						
					}else{
						f[i][j]+=f[t][j];
						if(f[i][j]>=P) f[i][j]-=P;
					}
				}
		}
	long long s=0;
	for(int i=m;i<=n;i++) s+=f[(1<<n)-1][i];
	cout<<s%P; 
 return 0;
}
