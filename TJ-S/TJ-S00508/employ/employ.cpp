/*
f[i][j]表示对于前i个人，通过的人数为j的方案数

如果第i个人不通过 f[i][j]=f[i-1][j]
如果第i个人通过：需要满足
	1. 

 
*/
#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
int n,m;
string s;
int a[510];
int f[510][510][510];//前i天，最后一天是第j个人， 通过人数为k的方案数 
int sum[510];//表示截止到目前第i个人做出的贡献 
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	s="#"+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]==0) continue;
		f[1][i][s[1]-'0'] = 1;
		sum[i]=1;
	}
	for(int i=2;i<=n;i++){//前i天
		for(int j=1;j<=n;j++){//最后一天是第j个人
			int res=0;
			for(int z=max(0,i-a[i]);z<=i;z++){//通过人数为z的方案数
				//满足前i-1个人，i-1-通过<a[i]
				//前i-1个人，通过>i-1-a[i]
				
				//2 1 1
				for(int k=1;k<=n;k++){
					if(k==j) continue;
					f[i][j][z+(s[j]-'0')] += f[i-1][k][z];//1 3 1
					f[i][j][z+(s[j]-'0')] -= sum[j];
//					f[i][j][z+(s[j]-'0')] = max(f[i][j][z+(s[j]-'0')],0);
					res+=f[i][j][z+(s[j]-'0')];
				}
			}
			sum[j]+=res;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=m;j<=n;j++){
			ans+=f[n][i][j];
		}
	}
	cout<<ans;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			for(int k=1;k<=n;k++){
//				cout<<i<<" "<<j<<" "<<k<<" : "<<f[i][j][k]<<"\n";
//			}
//		}
//	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
