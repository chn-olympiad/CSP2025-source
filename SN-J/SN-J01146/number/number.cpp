#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.length();
	vector<int>a(n);
	int cnt=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	if(cnt==1){
		cout<<a[0]<<endl;
		return 0;
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=cnt-2;i--){
		cout<<a[i];
	}
	return 0;
} 
