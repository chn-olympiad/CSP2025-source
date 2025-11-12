#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int lens=s.length();
	for(int i=0;i<lens;i++){
		if('0'<=s[i] and s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
