#include<iostream>
#include<cmath>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int m,n,x,a[101],h,cnt=0-n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(a[j]>=a[j+1]) {
				h=a[j];
				a[j]=a[j+1];
				a[j+1]=h;
			}
		}
	}
	
	
	
	
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=i;j++) {
			if((j*i+i*i)>a[n]) {
				cnt++;
			}
			
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
}
