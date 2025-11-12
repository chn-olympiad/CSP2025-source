#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
string s;
int l,tot;
int a[maxn];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			tot++;
			a[tot]=(s[i]-'0');
		}
	}
	sort(a+1,a+tot+1);
	for(int i=tot;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}