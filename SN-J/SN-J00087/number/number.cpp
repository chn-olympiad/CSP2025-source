#include <bits/stdc++.h>
using namespace std;
string s;
int m;
int n[1000001];
bool cmp(int n,int m){
	return n>m;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]>'z'||s[i]<'a'){
    		n[m]=int(s[i]-'0');
    		m+=1; 
		}
	}
	sort(n,n+1+m,cmp);
	for(int i=0;i<m;i++){
		cout<<n[i];
	} 
    return 0;
}

