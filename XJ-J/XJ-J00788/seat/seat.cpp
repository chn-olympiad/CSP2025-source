#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,sum=0;
	cin>>n;
	for(int a=1;a<=n;a++){
		for(int b=a;b>0;b/=10){
			if(b==b/10){
				sum++;
				cout<<a<<" "<<b;
			}
		}
	}cout<<sum;
	return 0;
}
