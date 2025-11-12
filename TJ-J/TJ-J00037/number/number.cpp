#include <bits/stdc++.h>
using namespace std;

string s,a;
int num[1000010];

int main(){
	freopen("number.in","r",stdin);
	freopen("nuber.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(i>=0 && i<=9){
			cin>>a;
		}
	}
	for(int i=0;i<a.size();i++){
		num[i]=a[i]-'0';
	}
	sort(num,num+1);
	cout<<num;
	return 0;
}