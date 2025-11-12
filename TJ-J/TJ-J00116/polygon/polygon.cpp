#include<bits/stdc++.h>
#include<stdio.h>
using namespace std; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int a[5005]={0};
	cin >> n;
	int d=1;
	for(int i=0;i<n;i++){
		cin >> a[i];
		if(a[i]!=1){
			d=0;
		}
	} 
	if(n<=2){
		cout << 0;
	}
	else{
		if(d==1){
			int ans=0;
			for(int i=3;i<=n;i++){
				int ji=1;
				for(int j=n;j>=n-i+1;j--){
					ji*=j;
				}
				cout << ji << endl;
				for(int j=2;j<=i;j++){
					ji/=j;
				}
				cout << ji << endl;
				ans+=ji;
			}
			cout << ans;
		}
		else{
			sort(a,a+n);
			if(n==3){
				if(a[2]<a[1]+a[0]){
					cout << 1;
				}
				else if(a[2]>=a[1]+a[0]){
					cout << 0;
				}
			} 
			else{
				int ans=1;
				int n1=n;
				while(n1>0){
					ans*=n1;
					n1--;
				} 
				cout << ans;
			}
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
