#include<bits/stdc++.h>
using namespace std;
stack<int> st; 
int main(){
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			st.push(s[i]);
			n++;
		}
	}
	int a[1000005];
	for(int i=1;i<=n;i++){
		int r=st.top();
		a[i]=r;
		st.pop();
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			if(a[j]>=a[j-1]) swap(a[j],a[j-1]);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
}
