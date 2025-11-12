#include<bits/stdc++.h>
using namespace std;
int l[500000],l1[500000];
int main(){
	int n,k,x=0,y=0,s=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=n;i++){
		for(int h=0;h<i;h++){
			for(int j=0;j<i;j++){
				x=x||l[j];
			}
			l1[h]=x;
			for(int j=0;j<i;j++){
				if(l1[h]==k){
					s++;
				}
			}
			if(s==i){
				y==i;
			}
		}
	}
	cout<<1||0||3;
	return 0;
}
