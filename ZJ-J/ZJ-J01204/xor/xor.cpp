#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		int num=0,i;
		for(i=1;i<=n;){
			if(a[i]==0){
				num++;
				i++;
			}
			else if(a[i]==a[i+1]){
				num++;
				i+=2;
			}
			else i++;
		}
		cout<<num;
	}
	else if(k==1){
		int num=0,i;
		for(i=1;i<=n;){
			if(a[i]==1){
				num++;
				i++;
			}
			else if(a[i]^a[i+1]==1){
				num++;
				i+=2;
			}
			else i++;
		}
		cout<<num;
	}
	else{
		int num=0,i;
		for(i=1;i<=n;){
			if(a[i]^a[i+1]==k){
				num++;
				i+=2;
			}
			else if(a[i]==k){
				num++;
				i++;
			}
			else i++;
		}
		cout<<num;
	}
	return 0;
}
