#include <bits/stdc++.h>
using namespace std;
bool o(int x,int y){
	return x>=y;
}
int z[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>47&&s[i]<58){
			z[a]=s[i]-48;
			a++;
		}
	}
	sort(z,z+s.size(),o);
	for(int i=0;i<a;i++){
		cout<<z[i];
	}
	return 0;
}
