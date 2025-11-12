#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int k;
string s;
char c[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size()-1;
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[++k]=s[i];
		}
	}
	sort(c+1,c+1+k,greater<char>() );
	for(int i=1;i<=k;i++){
		cout<<c[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
