#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
int b[505];
int main(){
	
	freopen("employ3.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	bool flag=1;
	int sum=0;
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		a[i]=int(c-'0');
		if(!a[i]){
			flag=0;
		}else{
			sum++;
		}
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(flag){
		long long int num=1;
		for(int i=n;i>=1;i--){
			num=num%998244353;
			num*=i;
			
		}
		cout<<num;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
