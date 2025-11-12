//于硕-SN-J00019-西安滨河学校 
#include<bits/stdc++.h>
using namespace std;
string s;
int a[1005];
int main(){
	freopen("mumber.in","r",stdin);
	freopen("mumber.out","w",stdout);
	int j=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	int n=j;
	sort(a+1,a+n+1);
	for(int i=n;i>=2;i--){
		cout<<a[i];
	}
	return 0;
}
