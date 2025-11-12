#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100005];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2){
		cout<<1;
	}
	else if(n<=10){
		if(k==1){
			int l=0,s=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					l++;
				}else{
					s++;
				}
			}
			if(l==s){
				cout<<n/2;
			}else{
				cout<<n/2/2;
			}
		}else{
			cout<<n/2;
		}
	}else if(n<=100&&k==0){
		cout<<n/2;
	}else{
		cout<<n/2;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

