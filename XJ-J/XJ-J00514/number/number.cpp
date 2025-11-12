#include <bits/stdc++.h>
using namespace std;
string s;
int k=1;
int num[100010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48 && s[i]<=57){
			int a=s[i]-48;
			num[k]=a;
			k++;
		} 
	}
	sort(num+1,num+k,cmp);
	for(int i=1;i<k;i++){
		cout<<num[i];
	}

	return 0;
}
