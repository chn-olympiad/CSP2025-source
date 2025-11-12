#include<bits/stdc++.h>
using namespace std;
int a[1000001],n,d;
string s;
int main(){
	freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			d++;
			a[d]=s[i]-'0';
		}
	}
	sort(a+1,a+d+1);
	for(int i=d;i>=1;i--)
	    cout<<a[i];
	return 0;
}
