#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
struct node{       
	int a;
	bool wangsunyi;
}e[maxn];                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
bool cmp(node x,node y){
	return x.a>y.a; 
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i = 0;i<s.size();i++){if(s[i]==' ')continue; 
		if(s[i]>='0'&&s[i]<='9'){ 
			e[i].a = s[i]-'0';
			e[i].wangsunyi = 1; 
		}
	}
	sort(e,e+s.size(),cmp);
	for(int i = 0;i<s.size();i++){
		if(e[i].wangsunyi==1){
			cout <<e[i].a; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
