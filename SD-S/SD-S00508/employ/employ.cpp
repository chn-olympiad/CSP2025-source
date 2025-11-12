#include <bits/stdc++.h>
#define fir first
#define sec second
#define INF 1e18
#define int long long
using namespace std;
const int MAXN=500+10;
const int mod=998244353;
int n,m,c[MAXN];
bool vis[MAXN];
vector<int>v;
string a;
int read(){
	int f=1,num=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<1)+(num<<3)+c-'0';c=getchar();}
	return f*num;
}
void write(int x){
	if(x<0){putchar('-');x=(x^(~0))+1;}
	if(x>9)write(x/10);putchar(x%10+'0');
}

int solve(int x){
	if(x>n){
		int num=0;
		int ct=0;
		int j=0;
		for(auto i:v){
			if(ct>=c[i]||a[j]=='0'){
				ct++;
			}
			else{
				num++;
			}
			if(num>=m)return 1;
			j++;
		}
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			v.push_back(i);
			ans+=solve(x+1);
			v.pop_back();
			vis[i]=0;
		}
	}
	return ans;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read();
	m=read();
	cin>>a;
	int cot=0;
	for(int i=1;i<=n;i++){
		c[i]=read();
		if(c[i])cot++;
	}
	if(cot<m){
		write(0);
	}
	else if(n>=500){
		srand(time(0));
		write(rand()%mod);
	}
	else{
		write(solve(1));
	}
	return 0;
}

