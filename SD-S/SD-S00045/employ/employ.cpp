#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
using namespace std;
int n,m,c[505];
const int mod=998244353;
long long f[505][505][505];//前i位，x个弃，大于x的书个数 方案 
string s=" ",s0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s0;
	s+=s0;
	int len=s.size();
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<c[i];j++) tot2[j]++;
		tot1[c[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=tot2[j];k++){
				if(s[i]=='1'){
					if(k>=1) f[i][j][k]=f[i-1][j][k-1]*(tot2[j]-k)%mod;
					if(j>=1){
						for(int p=0;p<=tot1[j]&&i-1-p-k>=0;p++){
							f[i][j][k]+=1ll*f[i-1][j-1][p+k]*(n-tot2[j]-tot1[j]-(i-1-p-k))*mod;
						}
					}
				}
//				else{
//					f[i][j][k]
//				}
			} 
		}
	}
	long long ans=0;
	for(int i=m;i<=n;i++){
		for(int j=0;j<=i;j++){
			ans+=f[len][len-i][j];
		}
		
	}
	cout<<ans;
	return 0;
}

