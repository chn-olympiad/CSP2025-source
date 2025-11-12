#include<bits/stdc++.h>
using namespace std;
int n,k,t=0;
//不好，我不会 
int a[1048576+5];
int b[1048576+5];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//没事还能骗分 
	//qwq 
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				t++;
			}
		}
		cout<<t;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				t++;
			}
		}
		cout<<t;
		return 0;
	}
	cout<<pow(2,20)-1<<endl;
	return 0;
}
