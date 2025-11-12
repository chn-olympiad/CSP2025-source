#include<bits/stdc++.h>
using namespace std;
string s,s1;
int j=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			s1+=s[i];
			j++;	
		}
 	}
 	for(int l=1;l<=j;l++){
 		for(int i=1;i<=j;i++){
			if(s1[i]>s1[i-1]){
				char c=s1[i];
				s1[i]=s1[i-1];
				s1[i-1]=c;
			}
		}
	}
	cout<<s1;
	return 0;
}
