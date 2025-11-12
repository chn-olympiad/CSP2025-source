#include<bits/stdc++.h>
using namespace std;
string s;
long long buck[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			buck[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(buck[i]>0){
			cout<<i;
			buck[i]--;
		}
	}
	return 0;
}