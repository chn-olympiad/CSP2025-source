#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,r;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')  r+=s[i];
	}
	char a;
	for(int i=0;i<r.size();i++){
		for(int j=0;j<r.size()-1;j++){
			if(r[j]<r[j+1]){
				a=r[j+1];
				r[j+1]=r[j];
				r[j]=a;
			}
		}
	}
	if(r[0]=='0'||r.empty())   cout<<0;
	else  cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
