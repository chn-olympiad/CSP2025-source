#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int N = 505;
const int Mod = 998244353;
void add(int &x,int y){
	x+=y;
	x-=(x>=Mod)*Mod;
}
int f[2][N][N],cnt[N],C[N][N],pre[N],jc[N];
int n,m;
char s[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n = read();m = read();
	scanf("%s",s+1);
	jc[0] = 1;
	for(int i=1;i<=n;i++){
		int x = read();
		cnt[x]++;
		jc[i] = jc[i-1]*i%Mod;
	}
	for(int i=0;i<=n;i++){
		C[i][0] = 1;
		for(int j=1;j<=i;j++){
			C[i][j] = C[i-1][j];
			add(C[i][j],C[i-1][j-1]);
		}
	}
	pre[0] = cnt[0];
	for(int i=1;i<=n;i++){
		pre[i]+=pre[i-1];
		pre[i]+=cnt[i];
	}
	f[0][0][0] = 1;
	for(int i=1;i<=n;i++){
		int now = i&1,lst = now^1;
		memset(f[now],0,sizeof(f[now]));
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				if(!f[lst][j][k]){
					continue;
				}
				if(s[i]=='1'){
					int z = n-pre[j]-k;
//					if(z>=1){//选>j 
						add(f[now][j][k+1],f[lst][j][k]);//钦定一个后面的填过来 
//					}
					z = pre[j]-(i-1-k);
					if(z>=1){//选<=j 
						for(int x=0;x<=min(k,cnt[j+1]);x++){
							add(f[now][j+1][k-x],f[lst][j][k]*z%Mod*C[k][x]%Mod*jc[x]%Mod*C[cnt[j+1]][x]%Mod);
						}
					}
				}else{
					int z = n-pre[j]-k;
//					if(z>=1){//>j
						for(int x=0;x<=min(k+1,cnt[j+1]);x++){
							add(f[now][j+1][k+1-x],f[lst][j][k]*C[k+1][x]%Mod*jc[x]%Mod*C[cnt[j+1]][x]%Mod);
//							cout<<"IJK:"<<i<<" "<<j<<" "<<k<<" "<<x<<"\n";
						}
//					}
					z = pre[j]-(i-1-k);
					if(z>=1){//<=j
//						cout<<"IJK:"<<i<<" "<<j<<" "<<k<<" "<<z<<"\n";
						for(int x=0;x<=min(k,cnt[j+1]);x++){
							add(f[now][j+1][k-x],f[lst][j][k]*z%Mod*C[k][x]%Mod*jc[x]%Mod*C[cnt[j+1]][x]%Mod);
						}
					}
				}
			}
		}
//		for(int j=0;j<=i;j++){
//			for(int k=0;k<=i;k++){
//				if(f[now][j][k]){
//					cout<<"F:"<<i<<" "<<j<<" "<<k<<" "<<f[now][j][k]<<"\n";
//				}
//			}
//		}
	}
	int ans = 0;
	for(int j=0;j<=n-m;j++){
		for(int k=0;k<=n;k++){
			int z = n-pre[j];
//			if(f[n&1][j][k]){
//				cout<<"JKZ:"<<j<<" "<<k<<" "<<z<<" "<<f[n&1][j][k]<<" "<<pre[j]<<"\n";
//			}
			
			if(z==k){
				add(ans,f[n&1][j][k]*jc[k]%Mod);
			}
		}
//		add(ans,f[n&1][i][0]);
	}
	cout<<ans<<"\n";
	return 0;
}

