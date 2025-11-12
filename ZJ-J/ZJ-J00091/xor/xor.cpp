#include<bits/stdc++.h>
using namespace std;
long long n,t,tt,cnt;
long long a[100100],cun[100100][30],sum[1510][1510][23];
bool can[2010],flag;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long ttt=a[i],x=1<<20,shu=20;
		while(shu>=0){
			if(ttt>=x){
				ttt-=x;
				cun[i][shu]=1;
			}
			x>>=1;
			shu--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=20;j++){
			sum[i][i][j]=cun[i][j];
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=0;k<=20;k++){
				sum[i][j][k]=(sum[i][j-1][k]+sum[j][j][k])%2;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			int l=j,r=j+i-1;
			flag=0,cnt=0;
			for(int kk=l;kk<=r;kk++){
				if(can[kk]==1){
					flag=1;
					break;
				}
			}
			if(flag==1) continue;
			for(int k=0;k<=20;k++){
				cnt+=(sum[l][r][k]%2)*(1<<k);
			}
			if(cnt==t){
				tt++;
				for(int kk=l;kk<=r;kk++){
					can[kk]=1;
				}
			}
		}
	}
	cout<<tt;
	return 0;
}
