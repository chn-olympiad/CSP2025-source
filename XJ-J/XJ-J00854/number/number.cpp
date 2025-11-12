#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int lonsi=s.size();
	int ii=0;
	for(int i=0;i<lonsi;i++){
		if(s[i]<'a'||s[i]>'z'){
			a[ii]=int(s[i])-48;
			ii++;
		}
	}
	sort(a,a+ii,cmp);
	for(int i=0;i<ii;i++){
		cout<<a[i];
	}
	return 0;
}//ciallo~
