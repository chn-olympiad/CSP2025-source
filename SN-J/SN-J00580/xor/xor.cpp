#include<bits/stdc++.h>
using namespace std;
int n,l,a[50005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>l;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x=a[i];
			if(i==j) x=a[i];
			else{
				for(int k=i+1;k<=j;k++){
					x^=a[k];
				}
			}
			if(x==l) {
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
