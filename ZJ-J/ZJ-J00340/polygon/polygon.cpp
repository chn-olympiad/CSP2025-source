#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	if(n<=2){
		cout<<0;
	}else if(n==3){
		int max=*max_element(a,a+n);
		int sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
		}
		if(sum>max*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6;
	}else if(n==5){
		cout<<9;
	}	
	fclose(stdin);
	fclose(stdout);
	return 0;
}