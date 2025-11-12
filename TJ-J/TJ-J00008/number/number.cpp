#include<bits/stdc++.h>
using namespace std;
int sm;
char mx=-1;
string s,su,sum;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	int q=s.length();
	for(int i=0;i<=q;i++){
		if(s[i]>='0'&&s[i]<='9'){
			sm++;
			su+=s[i];
		}
	}
	sort(su.begin(),su.end());
	for(int j=sm-1;j>0;j++){
		cout<<su[j];
	}
	return 0;
}
