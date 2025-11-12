#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N],cnt;
bool n0=0;
string s;
inline bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=(s[i]-'0');
		}
	}
	sort(a+1,a+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]!=0) n0=1;
		if(n0) printf("%d",a[i]);
	}
	if(!n0) printf("0");
	printf("\n");
	
	return 0;
}

