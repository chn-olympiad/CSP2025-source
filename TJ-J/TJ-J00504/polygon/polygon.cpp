#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,cnt = 0;
	cin>>n;
	int a[11111] = {};
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
		for(int i = 1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				for(int k = j+1;k<=n;k++){
					for(int l = 1;l<=n;l++){
						if(2*max(a[i],max(a[k],max(a[j],a[l])))<a[i]+a[k]+a[j]+a[l]){
							cnt++;
						}
					}
				}
			}
		}

	return 0;
}
