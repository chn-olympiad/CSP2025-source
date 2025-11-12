#include<bits/stdc++.h>
using namespace std;
#define int long long
string a;
int hs[10];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9')hs[a[i]-'0']++;
	}
	bool q=0;
	for(int i=9;i>=0;i--){
		while(hs[i]){
			hs[i]--;
			cout<<i;
			if(i==0&&!q)break;
			q=1;
		}
	}
	return 0;
}
