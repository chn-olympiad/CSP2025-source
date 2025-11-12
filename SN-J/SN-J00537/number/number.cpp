#include <bits/stdc++.h>
#define int long long
using namespace std;
string s;
int n=0,m; 
int a[1000005]; 
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	m=s.size()-1;
	for(int i=0;i<=m;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+m+1);
	while(n!=0){
		cout<<a[m];
		m--;
		n--; 
	}
	return 0;
 } 
