#include<bits/stdc++.h>
using namespace std;
long long sum[1000007]={0};
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int k = 0;
	cin >> s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sum[k]=int(s[i]-'0');
			k++;
		}
	}
	sort(sum,sum+k);
	for(long long i=k-1;i>=0;i--){
		cout << sum[i];
	}
	
	return 0;
}
