#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000050],tmp;
bool cmp(int x,int y){
	return x!=y?x>y:false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(a,0x3f3f,sizeof(a));
	cin>>s;
	for(int i=0;i<s.size();i++){
		char j=s[i];
		if(j>='0' and j<='9')a[tmp++]=j-'0';
	}
	sort(a,a+tmp,cmp);
	for(int i=0;i<=tmp;i++){
		if(a[i]<10)cout<<a[i];
	}
	return 0;
}