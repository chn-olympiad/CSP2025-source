#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int a[N],maxn;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=1;
	for(int i=0;i<=s.size();i++){
		if('0'<=s[i] and s[i]<='9'){
			a[j]=s[i]-'0';
			j++;
		}
	}
	sort(a+1,a+j+1);
	for(int i=j;i>1;i--){
		cout<<a[i];
	}
	return 0;
}
