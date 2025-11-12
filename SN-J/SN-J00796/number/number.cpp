#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int s1[N];
int p=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.length();i++){
		if (s[i]>=48&&s[i]<=57){
			s1[i]=s[i]-48;
			p++;
			
		}
	}
	sort(s1,s1+s.length(),cmp);
	for (int i=0;i<p;i++){
		cout<<s1[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
