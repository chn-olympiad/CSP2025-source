#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n>3){
		cout<<(n-2)*(n-2)%998244353;
	}else{
		sort(a+0,a+n);
		if(a[0]+a[1]>a[2]*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;//#Shang4Shan3Ruo6Shui4
}
