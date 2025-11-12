#include<bits/stdc++.h>
using namespace std;
int a[500010];
string a1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0,c;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]==k){
			sum++;
			continue;
		}
		for(int j=i;j<n;j++){
			
		} 
	}
	cout<<sum;
	return 0;
}
