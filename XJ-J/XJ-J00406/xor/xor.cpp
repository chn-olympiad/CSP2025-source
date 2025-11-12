#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0,c;
	cin>>n>>k;
	vector<int>a(n); 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			ans++;
			i++;
		}
		c=a[i];
		for(int j=i+1;j<n;j++){
			c=c^a[j];
			if(c==k){
				ans++;
				j++;
				c=a[j];
				i=j;
			}
		}
	}
	cout<<ans;
	return 0;
} 
