#include<bits/stdc++.h>
using namespace std;
char s[10000001];
int a[10000001];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t=1,q=0,s1=0;
	cin>>s;
	for(int i=1;i<=10000001;i++){
		if(s[s1]>='0' && s[s1]<='9'){
		a[t]=s[s1]-'0';
		t++;
	    }
	    s1++;
	}
	sort(a+1,a+1+t);
	for(int i=t;i>1;i--){
		cout<<a[i];
	} 
	return 0;
} 
