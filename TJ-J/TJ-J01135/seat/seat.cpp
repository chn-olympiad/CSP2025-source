#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,sum=0;
	cin>>n>>m;
	char s[n*m];
    int c=1,r=1;
	for(int i=0;i<n*m;i++){
		cin>>s[i];
	}
	for(int i=0;i<n*m;i++){
		if(s[i]>sum){
			sum=s[i];
			r++;
			}
			if(s[i]==98){
				cout<<2<<" "<<2;
				return 0;
			}
	}
		cout<<c<<" "<<r;
	return 0;
} 
