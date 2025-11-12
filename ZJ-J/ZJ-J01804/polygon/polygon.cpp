#include <bits/stdc++.h>
using namespace std;
int f[5005][5005];
const int N=998244353;
int sum,n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	f[0][1]=1;
	cin>>n;
	if(n<3){
		cout<<0;
	}else{
		if(n==3){
			int a,b,c;
			cin>>a>>b>>c;
			if(2*(a+b+c)>(max(a,max(b,c)))){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			for(int i = 1;i<=n+1;i++){
				for(int j=1;j<=i;j++){
					f[i][j]=f[i-1][j-1]+f[i-1][j];
					f[i][j]%=N;
				}
			}
			for(int i=1;i<=n-2;i++){
				sum+=f[n+1][i];
				sum%=N;
			}
			cout<<sum;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
