#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
string s;
int a[N],l;
inline int read(){
	int t=1,tot=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') t=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return tot*t;
}
inline int cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9')
			a[++l]=s[i]-'0';
	}
	sort(a+1,a+l+1,cmp);
	for(int i=1;i<=l;i++) cout<<a[i];
	return 0;
}
/*#Shang4Shan3Ruo6Shui4*/
