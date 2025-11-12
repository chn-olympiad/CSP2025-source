#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ("number.in","r",stdin);
	freopen ("number.out","w",stdout);
	string s,a;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0')
			a+=s[i];
	}
	int aa=a.size();
    for(int j=0;j<a.size();j++){
		for(int i=0;i<aa;i++){
			if(a[i]<a[i+1]){
				swap(a[i],a[i+1]);

			}
		}
		aa--;
    }

	cout<<a;
	return 0;
}