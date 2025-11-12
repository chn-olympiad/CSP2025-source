#include<bits/stdc++.h>
using namespace std;
string n,str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++)
	    if(n[i]>='0'&&n[i]<='9')
	        str.push_back(n[i]);
	sort(str.begin(),str.end(),greater<char>());
	cout<<str;
	return 0;
} 
