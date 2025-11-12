#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,s[10000];
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	if(n==1){
		if(s[0]!=0){
			cout<<0;
		}else{
			cout<<1;
		}
	}else if(n==2){
		if(s[0]|s[1]==0){
			cout<<1;
		}else{
			if(s[0]==0&&s[1]==0){
				cout<<2;
			}else{
				if(s[0]==0||s[1]==0){
					cout<<1;
				}else{
					cout<<0;
				}
			}
		}
	}
	return 0;
}
