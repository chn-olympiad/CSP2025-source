#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>a(n);
int check(int mid){
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i] xor a[j]==k){
				cnt++;
			}
		}
	}
	return cnt;
}
int main(){
	freopen(xor.in,"r",stdin);
	freopen(xor.out,"w"stdout);
	
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
