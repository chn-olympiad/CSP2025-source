#include<bits/stdc++.h>
using namespace std;
string s,a;
int main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a; 
	s+="";
	long long l=a.size();
	for(int i=0;i<l;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			s+=a[i];
		}
	}
	long long b=s.size();
	for(int i=0;i<b;i++){
		for(int j=b;j>=0;j--){
			if(s[i]<=s[j]){
				swap(s[i],s[j]);
			}
		}
	}
	cout<<s[b-1];
	for(int i=0;i<b-1;i++){
		cout<<s[i];
	}
}
