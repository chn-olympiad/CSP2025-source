#include<bits/stdc++.h>
using namespace std;
long long a,b,e,f[1000];
string c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c>>d;
	}
	for(int i=1;i<=b;i++){
		cin>>c>>d;
		int len=c.size();
		for(int j=0;j<len;j++){
			f[c[j]]++;
		}
		for(int i='a';i<='z';i++){
			if(f[i]==len){
				cout<<0;
			}
		}
	}
	return 0;
}