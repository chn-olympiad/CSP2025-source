#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int t=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<0;
	}else if(k==1){
		for(int i=0;i<n;i++){
			if(a[i]==1){
				t++;
			}
		}
		cout<<t;
	}
	return 0;
}
