#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
string s;
int a[maxn];
int n=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[n]=s[i]-48;
			n++;
		}
	}
	n--;
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
        cout<<a[i];
	}
	return 0;
}
