#include<bits/stdc++.h>
using namespace std;

const int N=1e6+10;

string s;
int c[N],ans[N];
int cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			c[++cnt]=s[i]-'0';
		}
	}
	int f=0;
	sort(c+1,c+1+cnt);
	reverse(c+1,c+1+cnt);
	for(int i=1;i<=cnt;i++){
		ans[i]=c[i];
		if(ans[i]!=0)f=1;
	}
	if(f){
		for(int i=1;i<=cnt;i++){
			cout<<ans[i];
		}
	}else{
		cout<<0;
	}
	
	return 0;
}
