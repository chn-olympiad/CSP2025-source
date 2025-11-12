//SN-J00435  Ðì×Ó³½  ³¤Çì°ËÖÐ
#include<bits/stdc++.h>
using namespace std;
string s,t;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=0;j<a[i];j++){
				t+=(char)i+'0';
			}
		}
	}
	cout<<t;
	return 0;
}
