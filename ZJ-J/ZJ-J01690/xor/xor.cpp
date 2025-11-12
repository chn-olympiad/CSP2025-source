#include<bits/stdc++.h>
using namespace std;
int a[1100];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=false;
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==flag){
			flag=0;
		}
		else{
			flag=1;
		}
		if(flag==k){
			cnt++;
			flag=0;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
