#include<bits/stdc++.h>
using namespace std;
int a[100000];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+1+n);
	int k=2,t=1;
	for(k=2;k<=n-1;k++){
		
		for(t=1;t+k<=n;t++){
			int p=0;
			int tot=0;
			for(int j=0;j<=k;j++){
				tot+=a[j+t];
				p=max(p,a[j+t]);
				
			}
			if(p*2<tot){
				ans=ans+(n-t-1)/k+1;
			
			}
		}
	}
	cout<<ans;
	return 0;
		
}
