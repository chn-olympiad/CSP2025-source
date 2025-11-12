#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;

string s;
int a[N],l;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++l]=s[i]-'0';
		}
	}
	sort(a+1,a+1+l);
	for(int i=l;i>=1;i--){
		printf("%d",a[i]);
	}
	return 0;
}
 
