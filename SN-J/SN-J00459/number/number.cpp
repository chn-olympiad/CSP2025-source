#include <bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0;
	n=s.size();
	for(int i=1;i<=n;i++){
		if(s[i]<=9&&s[i]>=1){
			a[i]=s[i];
		}	
	}
	sort(a+1;a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i];
	}
	return 0;
	
}
