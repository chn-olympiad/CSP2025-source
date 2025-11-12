#include<bits/stdc++.h>
using namespace std;
char b[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=sizeof(s);
	for(int i=1;i<=n;i++){
		if(s[i]>='1'&&s[i]<='9'&&s[i]!='a'&&s[i]!='b'&&s[i]!='c'&&s[i]!='d'&&s[i]!='e'&&s[i]!='f'&&s[i]!='g'&&s[i]!='h'&&s[i]!='j'&&s[i]!='k'&&s[i]!='l'&&s[i]!='m'&&s[i]!='n'&&s[i]!='o'&&s[i]!='p'&&s[i]!='q'&&s[i]!='r'&&s[i]!='s'&&s[i]!='t'&&s[i]!='u'&&s[i]!='v'&&s[i]!='w'&&s[i]!='x'&&s[i]!='y'&&s[i]!='z'){
		    b[i]=s[i];	
		}
	}
	sort(b,b+n+1);
	for(int i=n;i>=1;i--)
	cout<<b[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

