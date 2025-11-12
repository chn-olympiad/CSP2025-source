#include<bits/stdc++.h>
using namespace std;
string s;
int n,max;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int q=0,a[s.size()];
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			a[q]=s[i]-48;
			q++;
		}
	}
	
	sort(a,a+q);
	for(int i=q-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 
