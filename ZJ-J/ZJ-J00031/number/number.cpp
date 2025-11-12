#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;

int j;
int a[N];
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a,a+j);
	for(int i=j-1;i>=0;i--)
		cout<<a[i];
	return 0;
}
