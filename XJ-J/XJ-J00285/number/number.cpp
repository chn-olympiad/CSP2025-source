#include<bits/stdc++.h>
using namespace std;
int main(){
	int s,sum=0;
	cin>>s;
	for(int i=0;i<=s;i++){
		for(int j=0;j<i;j++){
			if(s>='0'||s<='9'){
				sum++;
			}
		}
		cout<<sum;
	}
	
	
	return 0;
}