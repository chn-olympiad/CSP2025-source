#include<bits/stdc++.h>
using namespace std;
int sum[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int m=s.size();
	for(int i=0;i<m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			int n=s[i]-'0';
			sum[n]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(sum[i]>0){
			cout<<i;
			sum[i]--;
		}
	}
	return 0;
}

