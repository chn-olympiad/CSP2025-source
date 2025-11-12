#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin >> n>> m;
	int a[n+101],x[n+101];
	for(int i=1;i<=n;i++){
		cin >> a[i];
		x[i]=1;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==m&& x[i]){
			ans++;
			x[i]=0;
			continue;
		}
		if(!x[i]){
			continue;
		}
		int s=a[i];
		for(int j=i+1;j<=n;j++){
			if((s^a[j])==m && a[j]!=m && x[j]){
				ans++;
				for(int k=i;k<=j;k++){
					x[k]=0;
				}
				break;
			}else if(a[j]!=m && x[j]){
				s^=a[j];
			}else{
				break;
			}
		}		
	}
	cout << ans;
	return 0;
} 
