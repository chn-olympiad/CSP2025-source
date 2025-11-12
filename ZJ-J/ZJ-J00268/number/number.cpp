#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
char s[N],a[N];
int cnt;
int main(){	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[++cnt]=s[i];
		}
	}
	sort(a+1,a+cnt+1);
	if(a[cnt]=='0'){
		cout<<0<<endl;
		return 0;
	}
	for(int i=cnt;i>0;i--) cout<<a[i];
	return 0;
}
