#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l=0;
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	for(int i=l;i>0;i--){
		cout<<a[i];
	}
} 
