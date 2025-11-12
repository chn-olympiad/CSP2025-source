#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int id=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	
	for(int i=0;i<int(s.size());i++){
		if(47<s[i]&&s[i]<58){
			a[id]=s[i]-48;
			id++; 
		}
	}
	sort(a,a+id,greater<int>());
	for(int i=0;i<=id;i++){
		cout<<a[i];
	}
	return 0;
}
