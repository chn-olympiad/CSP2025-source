#include <bits/stdc++.h>
using namespace std;
char a[1000010];
string ans;
int la,cnt[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	la=strlen(a);
	for (int i=0;i<la;i++){
		if (a[i]>='0'&&a[i]<='9') cnt[a[i]-'0']++;
	}
	for (int i=9;i>=0;i--){
		for (int j=1;j<=cnt[i];j++){
			ans+=i+'0';
		}
	}
	cout<<ans;
	return 0;
}

