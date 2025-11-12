#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string s1="";
	int cnt1=0;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(isdigit(s[i])){
			s1+=s[i];
			cnt1++;
		} 
	}
	if(cnt1==len){
		sort(s1.begin(),s1.end());
		reverse(s1.begin(),s1.end());
		cout<<s1;
		return 0;
	}
	sort(s1.begin(),s1.end());
	reverse(s1.begin(),s1.end());
	cout<<s1;
	return 0;
}