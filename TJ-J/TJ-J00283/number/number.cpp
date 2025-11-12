#include<bits/stdc++.h>
using namespace std;
string s="",ss="";
long long cnt=0;
int main(){
	freopen("number.in","r",stdin);//
	freopen("number.out","w",stdout);/////
	cin>>s;
	long long l=s.length();
	//cout<<s<<endl; l==0 cnt==0
	for(long long i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss+=s[i];
			cnt++;
		}
	}
	sort(ss.begin(),ss.end());
	if(ss[cnt-1]=='0'){
		cout<<0;
		return 0;
	}
	for(long long i=cnt-1;i>=0;i--){
		cout<<ss[i];
	}
	return 0;
}
