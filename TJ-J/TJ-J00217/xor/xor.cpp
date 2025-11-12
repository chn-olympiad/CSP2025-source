#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
int a[500000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int t=a[i];
			for(int x=i+1;x<=j;x++){
				t=t^a[x];
			}
			if(t==k) cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
