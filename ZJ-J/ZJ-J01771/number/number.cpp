#include<bits/stdc++.h>
using namespace std;
char s[1000010],n;
int ans[1000010],a,b;
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>n){
		b++;
		s[b]=n;
	}
	for(int i=1;i<=b;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a++;
			ans[a]=s[i]-'0';
		}
	}
	sort(ans+1,ans+1+a,cmp);
	for(int i=1;i<=a;i++){
		cout<<ans[i];
	}
	return 0;
}
