// T1 number
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#define int long long
#define gc getchar 
#define pc putchar
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pre(i,a,b) for(int i=(a);i>=(b);--i)
#define IO
using namespace std;
namespace Fast{
	inline int rd(){
		int n(0),f(1);char c=gc();
		while(c<'0'||c>'9'){
			if(c=='-') f=-1;
			c=gc();
		}
		while(c>='0'&&c<='9'){
			n=(n<<1)+(n<<3)+(c^48);
			c=gc();
		}
		return n*f;
	}
	inline void print(int n){
		if(n<0)pc('-');
		if(n>9) print(n/10);
		pc(n%10^48);
		return;
	}
	inline void echo(int n,char c){
		print(n),pc(c);
		return;
	}
}using namespace Fast;
const int N=1000005;
string s;
signed main(){
#ifdef IO
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
#endif
	cin>>s;
	sort(s.begin(),s.end(),greater<char>());
//	cout<<s;
	for(char c:s) if(c<='9'&&c>='0') pc(c);
#ifdef IO
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
} 
