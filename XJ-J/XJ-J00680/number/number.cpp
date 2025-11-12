#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int num[N],c=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[c]+=(int)s[i]-48;
			c++;
		}
	}
	sort(num+1,num+1+c);
	reverse(num+1,num+1+c);
	for(int i=1;i<c;i++)cout<<num[i];
	return 0;
} 
