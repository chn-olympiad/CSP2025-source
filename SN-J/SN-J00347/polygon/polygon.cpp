//SN-J00347 张昊阳 西安滨河学校
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int j;
	int k;
	cin >>n>>k;
	for(int i=0;i<=n;i++){
		if(n>=0){
			cout<<n;
		}else if(n<=3){
			cout<<"cross"; 
		}
	}
    cout<<k;
}
