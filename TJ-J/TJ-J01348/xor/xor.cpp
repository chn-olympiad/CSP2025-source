#include<bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("xor","r",stdin);
	freopen("xor","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int s=0; 
	for(int i=1;i<=n;i++){
		int o=a[i];
		if(a[i]==k)s++;
		for(int j=i+1;j<=n;j++){
			o^=a[j];
			if(o==k){
				s++;
				i=j+1;
			}
		}
	}
	cout<<s;
	return 0;
}

