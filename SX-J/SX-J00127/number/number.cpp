#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int a[N];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    string s;
    int x=1;
    cin>>s;
    for(int i=0;i<=s.size();i++){
    	if(s[i]=='0'){
			a[x]=0;
			x++;
		}
		if(s[i]=='1'){
			a[x]=1;
			x++;
		}
		if(s[i]=='2'){
			a[x]=2;
			x++;
		}
		if(s[i]=='3'){
			a[x]=3;
			x++;
		}
		if(s[i]=='4'){
			a[x]=4;
			x++;
		}
		if(s[i]=='5'){
			a[x]=5;
			x++;
		}
		if(s[i]=='6'){
			a[x]=6;
			x++;
		}
		if(s[i]=='7'){
			a[x]=7;
			x++;
		}
		if(s[i]=='8'){
			a[x]=8;
			x++;
		}
		if(s[i]=='9'){
			a[x]=9;
			x++;
		}
	}
	sort(a+1,a+x+1);
	for(int i=x;i>1;i--){
		cout<<a[i];
	}
	return 0;
}