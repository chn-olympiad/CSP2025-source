#include<bits/stdc++.h>
using namespace std;
string s;
struct str{
	char a;
};
str s1[1000000];
int q=0;
bool pan(str x,str y){
	return x.a>y.a;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ln=s.size();
	for(int i=0;i<ln;i++){
		if(s[i]>=48 and s[i]<=57){
			s1[q].a=s[i];
			q++;
		}
	}
	sort(s1,s1+q,pan);
	for(int i=0;i<q;i++){
		cout<<s1[i].a;
	}
	return 0;
}
