#include<bits/stdc++.h>
using namespace std;
int n,a[5005],cnt=0,t=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(t!=n-1){
		for(int i=t+2;i<=n;i++){
			for(int j=1;j<=i-t-1;j++){
				int sum=0;
				for(int k=j;k<=j+t;k++){
					sum+=a[k];
				}
				if(sum>a[i]){
					cnt++;
				}
			} 
		}
		t++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
