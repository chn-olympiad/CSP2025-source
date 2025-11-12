#include <bits/stdc++.h>
using namespace std;

int mm[100001];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),j=0;
	for(int i=0;i<n;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			mm[j]=s[i]-'0';
			j++;
		}
	}
	sort(mm,mm+j+1,cmp);
	for(int i=0;i<j;i++){
		cout<<mm[i];
	}
	return 0;
}
