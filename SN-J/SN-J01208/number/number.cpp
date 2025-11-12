#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a=1,b,c,d,e,f,g,h;
int aa[N];
string s;
int main(){
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			aa[a]=s[i]-48;
			a++;
		}
	}
	sort(aa+1,aa+a+1);
	for(int i=a;i>=2;i--){
		cout<<aa[i];
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
