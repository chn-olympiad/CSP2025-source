#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	int n,z;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int C=0,c=0;
	for(int i=3;i<n;i++){
		for(int j=0;j<n-i+1;j++){
			for(int k=0;k<i;k++){
				C+=a[k];
				c=max(a[k],c);			
			}
			if(C>2*c){
				z++;
			}
		}
	}
	cout<<z;
	return 0;
}