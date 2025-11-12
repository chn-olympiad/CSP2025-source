#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	int f=1;x=0;char s=getchar();
	while(s<'0'||s>'9'){if (s=='-'){f=-f;}s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-'0';s=getchar();}
	x*=f;
}
const int MAXN=1e6+5;
string s;
int a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int n=s.length();
	for (int i=0;i<n;i++){
		if (s[i]>='0' && s[i]<='9') a[s[i]-'0']++;
	}
	bool flag=false;
	s="";
	for (int i=9;i>=0;i--){
		if (i && a[i]) flag=true;
		if (i || (i==0 && flag)){
			for (int j=1;j<=a[i];j++) s+=(char)(i+'0');
		}
	}
	if (flag) cout<<s;
	else cout<<0;
	return 0;
}
//100pts?
