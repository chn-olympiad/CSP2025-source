#include<bits/stdc++.h>
using namespace std;
long long n,m,c,i,j,k;
string s;
int a[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cin>>s;
	k=0;
	for(i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n=s[i]-48;
			a[k]=n;
			k++;
		}
	}
	sort(a,a+k);
	for(i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
