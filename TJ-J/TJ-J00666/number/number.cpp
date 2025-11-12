#include <bits/stdc++.h>
using namespace std;
string s,a[1000005];
long long x;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<=s.size();j++){
			if(s[j]<s[j+1]){
				int c=0,d=0;
				c=s[j];
				d=s[j+1];
				s[j]=d;
				s[j+1]=c;
				
			}
		}
		//cout<<s<<" ";
	}
	cout<<s; 
	return 0;
}
