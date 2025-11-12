#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[50005];
int qz[50005],cnt;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qz[i]=a[i]+qz[i-1];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=i+1;k<=n;k++){
				if(qz[k]-qz[j-1]+a[i]>a[k]*2){
					cnt++;
				}
			}
			
		}
		cout<<cnt<<endl;
	}
	cout<<cnt;
	return 0;
}

