#include<bits/stdc++.h> 
using namespace std;
const int N=1e6+5;
char s[N];
int a[N],h,len;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=strlen(s);
	for(int i=0;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9')a[++h]=s[i]-48;
	}
	sort(a+1,a+h+1);
	for(int i=h;i>0;i--)cout<<a[i];
	return 0;
}

