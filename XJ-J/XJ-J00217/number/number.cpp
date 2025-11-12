#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int vis[1000005],len,cnt=0,a[1000005];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>(s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=(int)(s[i])-48;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) cout<<a[i];
}
