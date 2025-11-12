#include<bits/stdc++.h>
using namespace std;
string s;
int sum[20];
int main(){
	cin>>s;
	for(int i=0;i<int(s.size());i++){
		if(isdigit(s[i])) sum[int(s[i]-'0')]++;
	}for(int i=9;i>=0;i--){
		if(sum[i]>0){
			for(int j=1;j<=sum[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
