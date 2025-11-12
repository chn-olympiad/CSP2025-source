#include<bits/stdc++.h> 
using namespace std;
int n,k,a[5000010],ans,m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		m=a[i];
		for(int j=i-1;j<n;j++){
			for(k=i;k<=j;k++){
				m=a[k]^m;
			}
			if(m==k){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
