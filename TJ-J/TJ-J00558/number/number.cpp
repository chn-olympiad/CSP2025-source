#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>
#include<string>
#include<queue>
#define long long long
using namespace std;
bool cmp(long a,long b){
	if(a!=b) return a>b;
}
long a[1000009],n=0,xb=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			n++;
			xb=i;
		}
	}
	sort(a,a+xb,cmp);
	for(int i=0;i<n;i++){
		printf("%lld",a[i]);
	}
	return 0;
}

