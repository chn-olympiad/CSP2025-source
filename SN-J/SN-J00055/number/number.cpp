#include<bits/stdc++.h>
using namespace std;
#define int long long
#define FI(x) freopen(x".in","r",stdin)
#define FO(x) freopen(x".out","w",stdout)
string s;
int v[100000010];
signed main(){
	//×¢ÒâÌæ»»ºÍ×¢ÊÍ
	FI("number");
	FO("number");
	cin>>s;
	int x=0;
	for(int i=0;i<s.size();i++){
		char a=s[i];
		if(a-'0'<49){
			x++;
			v[x]=a-'0';
		}
	}
	sort(v+0,v+x+1);
	for(int i=x;i>=1;i--){
		cout<<v[i];
	}
	return 0;
}

