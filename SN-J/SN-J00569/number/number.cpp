#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
string s,ss;
long long a[100005];
int j=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>='0'&&s[i]<='9'){
			ss[j]=s[i];
			j++;
		}
	}
	j--;
	for(int i=0; i<=j; i++){
		a[i]=ss[i]-'0';
		
	}
	sort(a,a+j+1,cmp);
	
	for(int i=0; i<=j; i++){
		cout<<a[i];
	}
	return 0;
} 
