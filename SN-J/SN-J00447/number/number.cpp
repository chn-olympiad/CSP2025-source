#include<bits/stdc++.h>
#define forf(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int N=1e6+5;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length(),cnt=0;
	for (int i=0 ; i<len ; i++){
		if (s[i]>='0' && s[i]<='9'){
			   a[i]=s[i]-48;
			   cnt++;
		}
	}
	sort(a,a+len,cmp);
	forf(i,0,cnt-1){
		cout<<a[i];
	}
	
	return 0;
}

