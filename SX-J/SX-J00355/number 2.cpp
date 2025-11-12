#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int grade[5],b;
	cin>>grade[5];
	for(int i;i<5||i>1;i++){
		int grade[i];
		for(int j=1;j<i;j+=0){
			int grade[j];
			if(grade[j]<grade[i]){
			b++;
		}
		}
	}int c,r;
	c=b/n+1;
	r=b%n+1;
	cout<<'c r';
    return 0;}

