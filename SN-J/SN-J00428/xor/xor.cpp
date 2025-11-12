#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x==1){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
