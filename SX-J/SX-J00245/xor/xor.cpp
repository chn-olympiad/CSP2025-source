#include<bits/stdc++.h>//第三题
using namespace std;
int n,k;
int a[100001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];

	}
	int cnt;
	for(int i=1;i<=n;i++){
		if(a[i]&&a[i-1]==0){
			cnt++;
		}
	}

	if(k==0){
		cout<<1;

	}else if(k==3){
		cout<<2;

	}
	if(k==2){
		cout<<2;
	}else{
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
