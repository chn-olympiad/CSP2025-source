#include<bits/stdc++.h>
using namespace std;
int a[1000007];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),cnt=0;
	for(int i=0;i<l;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[i+1]=s[i]-'0';cnt++;
		}

	}
	sort(a+1,a+1+l,cmp);
	for(int i=1;i<=cnt;i++){
		printf("%d",a[i]);
	}
	return 0;
}