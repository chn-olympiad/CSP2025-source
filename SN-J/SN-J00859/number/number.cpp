#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
char s[N];
int a[N];
long long o;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long l=strlen(s);
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[o]=s[i];
			o++;
		}
	}
	sort(a,a+o,cmp);
	if(a[0]==0){
		cout<<0;
		return 0;
	}
	for(int i=0;i<o;i++){
		cout<<a[i]-'0';
	}
	return 0;
}
