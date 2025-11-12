#include<bits/stdc++.h>
using namespace std;
int n;
int a[5500];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=0;
	sort(a+1,a+n+1,cmp);
	int k=3;
	while(k<=n){
		if(k==3){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					for(int p=j+1;p<=n;p++){
						if(2*a[i]<a[i]+a[j]+a[p]){
							t++;
					
						}
					}
				}
			}
		}

		k++;
	}
	cout<<t;
	return 0;
}
