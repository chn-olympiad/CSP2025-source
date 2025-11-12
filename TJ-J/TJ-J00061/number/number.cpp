#include<bits/stdc++.h>
using namespace std;
int c[1000010];
bool pan(char a){
	if(a>='0'&&a<='9'){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long k=0;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(pan(s[i])){
			c[k]=s[i]-'0';
			k++;
		}
	}
	sort(c,c+k);
	for(long long i=k-1;i>=0;i--){
		cout<<c[i];
	}
	cout<<endl;
	return 0;
}
