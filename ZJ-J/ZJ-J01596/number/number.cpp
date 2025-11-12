//T1
//9:07 idea
//9:09 AC
//9:12 check
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
	while(ch>='0'&&ch<='9')ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
string s;
int a[N],tot;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++tot]=s[i]-'0';
		}
	}
	sort(a+1,a+1+tot);reverse(a+1,a+1+tot);
	for(int i=1;i<=tot;i++)write(a[i]);
	return 0;
}