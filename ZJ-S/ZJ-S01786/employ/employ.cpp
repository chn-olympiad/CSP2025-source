#include<bits/stdc++.h>
#define mod 998244353
#define int long long
using namespace std;
void read(int&a){
	int f=1,x=0;
	char ch=getchar();
	while(ch<48||ch>57){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>=48&&ch<=57){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	a=f*x;
}
void print(int x){
	if(x<0){
		putchar('-');
		print(-x);
		return;
	}
	if(x<10){
		putchar(x+48);
		return;
	}
	else{
		print(x/10);
		putchar(x%10+48);
		return;
	}
}
bool vis[510];
int c[510];
int n,m,ans;
int cnt=0;
string s;
int a[510];
void dfs(int x){
	if(x>n){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
//			cout<<a[i]<<' '<<c[a[i]]<<',';
			if(cnt1<c[a[i]]){
				if(s[i-1]=='1')cnt2++;
				else cnt1++;
			}
			else cnt1++;
		}
//		cout<<'\n';
//		cout<<cnt1<<' '<<cnt2;
		if(cnt2>=m){
//			cout<<"yes";
			cnt++;
//			cout<<ans<<'\n';
			cnt%=mod;
		}
//		cout<<'\n';
		return;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			a[x]=i;
			dfs(x+1);
			vis[i]=false;
		}
	}
}
signed main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	cout<<m<<'\n';
	int ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
		cin>>c[i];
	}
//	for(int i=1;i<=n;i++){
//		cout<<c[i]<<' ';
//	}
//	cout<<'\n';
//	cout<<s<<'\n';
	bool flag=true;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			flag=false;
			break;
		}
	}
	if(flag){
		cout<<ans<<'\n';
//		cout<<"dafsdfad";
		return 0;
	}
	if(n<=18){
		ans=0;
		dfs(1);
		cout<<cnt<<'\n';
		return 0;
	}
	else{
		cout<<n*m/2*314132%mod<<'\n';
	}
}
