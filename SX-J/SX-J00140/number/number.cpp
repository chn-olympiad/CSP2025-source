#include<bits/stdc++.h>
using namespace std;
long long c[100000],d;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int b=a.size();
	for(int i=0;i<b;i++){
		if(a[i]>='1'&&a[i]<='9'){
			c[a[i]-'1'+1]++;
			d++;
		}
		if(a[i]=='0'){
			c[0]++;
			d++;
		}
	}
	for(int i=9;i>=0;){
		if(c[i]!=0){
			cout<<i;
			c[i]--;
		}
		else
		i--;
	}
	return 0;
}