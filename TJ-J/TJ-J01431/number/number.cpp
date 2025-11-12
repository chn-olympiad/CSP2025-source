#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int n[100005],k=0;
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
 	    if(s[i]>='0'&&s[i]<='9'){
			n[k]=s[i]-'0';
			k++;
		}
	}
	sort(n,n+k);
	for(int i=k-1;i>=0;i--){
		printf("%d",n[i]);
	}
	return 0;
}
