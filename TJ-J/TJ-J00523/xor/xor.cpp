#include<bits/stdc++.h>
using namespace std;
int a[666666],n,k,dp[666666],m,cnt,b;
void fz(int p,int q){
	for(int i=p;i<=q;i++){
		a[i]=-1;
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0);
	cin>>n>>k;
	m=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			dp[i]=a[i];
		}
		dp[i]=a[i]^dp[i-1];
	}
	for(int i=0;i<=n;i++){
		//int i=2;
		if(m<=i){
			break;
		}
		for(int j=1+i;j<=n;j++){
			int d=dp[j]^dp[j-i-1];
			//
			if(a[j]!=-1&&a[j-i]!=-1&&d==k){
				bool bo=0;
				for(int k=j-i;k<=j;k++){
					if(a[k]==-1){
						bo=1;
						break;
					}
				}
				if(bo){
					continue;
				}
				if(j-b==i){
					fz(j-i,j);
				}
				//cout<<i<<" "<<m<<";";
				//cout<<a[j]<<" "<<a[j-i]<<":"<<dp[j]<<" "<<dp[j-i-1]<<"="<<d<<"\n";
				cnt++;
				fz(j-i,j);
				b=j;
				m=m-(i+1);
			}
		}
	}
//	for(int i=1;i<=n;i++){
	//	cout<<a[i]<<" ";
	//}
	//cout<<"\n";
	cout<<cnt;
	return 0;
} 
