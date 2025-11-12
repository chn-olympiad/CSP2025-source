#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000010];
int b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int j=1;
	int l=s.length();
	for(int i=1;i<=l;i++){
		a[i]=s[i-1];
		if(a[i]-'0'>=0&&a[i]-'0'<=9){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b+1,b+j);
	for(int i=j-1;i>=1;i--){
		cout<<b[i];
	}
	
} 
