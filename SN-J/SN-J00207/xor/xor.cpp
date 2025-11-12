#include<iostream>
#include<cstdio>

using namespace std;

int l[1000];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>l[i];
	}
	if(k==0){
		cout<<0;
	}
	else if(k==1){
		int cnt;
		for(int i=1;i<=n;i++){
			if(l[i]==1){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
} 
