#include<bits/stdc++.h>
#define int long long
//#define il inline
#define put putchar
#define pii pair<int,int>
#define mk make_pair
using namespace std;
/*il int rd(int x){
	int sum=0,p=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')p=-1;ch=getchar();}
	while(isdigit(ch)){sum=sum*10+(ch-'0');ch=getchar();}
	return sum*p;
}
il void wr(int x){
	if(x<0)put('-'),x=-x;
	if(x>9)wr(x/10);
	put(x%10+'0');
}*/
const int JYAAKIOI=1e18,N=1e6+10;
string s;
int n,a[N],tot;
signed main(){
	//system("fc number.out number4.ans");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	s=' '+s;
	n=s.size()-1;
	for(int i=1;i<=n;++i)if(isdigit(s[i]))a[++tot]=s[i]-'0';
	sort(a+1,a+1+tot);
	for(int i=tot;i>=1;--i)cout<<a[i];
	return 0;
}
