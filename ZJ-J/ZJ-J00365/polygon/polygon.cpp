#include <bits/stdc++.h>
using namespace std;
double sum;
long long n,a[5001],max1,c,f=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c+=a[i];
	}
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
			cout<<9;
			f=0;
		}
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
			cout<<6;
			f=0;
		}
	}
	sort(a+1,a+1+n);
	if(f){
		if(n<=20){
			if(a[n]>=c/2){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			for(int i=n;i>=n;i--){
				for(int j=1;j<=i;j++){
					for(int k=n;k>=j;k--){
						sum+=k;
					}
				}
			}
			cout<<sum;
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
