#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10],ans;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n = s.size();
	for(int i=0;i<=n-1;i++){
		if(s[i]>='0'&&s[i]<='9')
			a[s[i]-'0']++;
	}
	int v = 9;
	while(v!=-1){
		if(a[v]>0){
			ans = ans*10+v;
			a[v]--;
		}
		else v--;
	}
	printf("%lld",ans);
	return 0;
}
