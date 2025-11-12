#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[114514],l;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[l]=s[i]-'0';
			l++;
		}
	}
	sort(a,a+l);
	if(a[l-1]==0){
		cout<<0;
	}else{
		for(int i=l-1;i>=0;i--){
			cout<<a[i];
		}
	}
	return 0;
} 
