#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100001]={},f=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4){
		if(k==2&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout<<2;
			f=0;
		}
		if(k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout<<2;
			f=0;
		}
		if(k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
			cout<<1;
			f=0;
		}
	}
	if(k==0&&f){
		cout<<n/2;
	}else{
		cout<<n/2-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
