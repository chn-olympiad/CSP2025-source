#include<bits/stdc++.h>
using namespace std;
int main(){
	//SN-S00672 贾羽鹤 陕西省西安中学  
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	unsigned long long ans=0;
	cin>>n>>m;
	ans=n;
	if(m==1){
		cout<<n;
		return 0;
	}else if(m==n){
		for(int i=m-1;i>0;i--){
			ans*=i;
			ans%=(998244353);
		}
		
		cout<<ans;
		return 0;
	}
	for(int i=m-1;i>0&&n>0;i--){
		ans*=(n-1);
		ans%=(998244353);
		n--;
	}
	
	cout<<ans;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
