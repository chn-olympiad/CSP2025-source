#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n[s.size()];
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			char a=s[i];
			n[cnt]=a-'0';
			cnt++;
		}
	}
	for(int i=0;i<cnt;i++){
		for(int j=i+1;j<cnt;j++){
			if(n[j]>n[i]) swap(n[j],n[i]);
		}
	}
	string s1;
	for(int i=0;i<cnt;i++){
		char a=n[i]+'0';
		s1[i]=a;
		cout<<s1[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
