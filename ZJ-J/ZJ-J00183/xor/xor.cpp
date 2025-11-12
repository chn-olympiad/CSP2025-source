#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
int a[500005];
int x;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]){
			x++;
		}
	}
	if(k==1){
		cout<<x;
		return 0;
	}
	if(k==0){
		long long s=0;
		for(int i=1;i<n;i++){
			if(a[i]&&a[i+1]){
				i++;
				s++;
			}
		}
		cout<<n-x+s;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
