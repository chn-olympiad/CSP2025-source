#include<bits/stdc++.h>
using namespace std;
string s;
int N=1e6+10;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int a=s.size(),b[N],c=1;
	if(a==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<a;i++){
		if(s[i]<'9'&&s[i]>'0'){
		cout<<s[i];
		b[c]=s[i];
		c++;
		}
	}
 for(int i=0;i<c-1;i++){
		for(int j=1;j<c;j++){
			if(b[i]<b[j]) swap(b[i],b[j]);
		}
		cout<<b[i];
	}
	return 0;
}