#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	int a=0||1||2||3||4||1||0||1||0||1||0||0||0||0||0||1||1||0;
	string s1,s2;
	string t1,t2;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		for(int j=1;j<=q;j++){
			cin>>t1>>t2;		
			a++;	
		}
		cout<<a;
	}
	cout<<endl;
	return 0;
} 
