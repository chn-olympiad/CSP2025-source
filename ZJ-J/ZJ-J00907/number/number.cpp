#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int n=s.length(),t=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t++;
			num[t]=s[i]-'0';
		}
	}
	sort(num+1,num+t+1);
	for(int i=t;i>=1;i--){
		cout<<num[i];
	}
	return 0;
}
