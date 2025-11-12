#include<bits/stdc++.h>
using namespace std;
long long n,k,a[10010],s,f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(f!=a[i]){
				s++;
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(f==a[i]){
				s++;
				f=0;
			}
			else{
				f=1;
			}
		}
	}
	cout<<s;
}

