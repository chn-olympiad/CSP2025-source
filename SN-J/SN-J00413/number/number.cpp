#include<bits/stdc++.h>//100pts
#define int long long
using namespace std;
string s;
int a[1000005],tot;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if((int)s[i]>=(int)'0'&&(int)s[i]<=(int)'9'){
			a[++tot]=(int)(s[i]-'0');
		}
	}
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
