#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=1e6+5;
const int eps=1e-6;
const int mod=1e9+7;
int read(){
	int k=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		k=k*10+ch-'0';
		ch=getchar();
	}
	return k*f;
}
int n,m;
long double a[N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	long double s=a[1];
	int pos=0;
	for(int i=1;i<=n*m;i++)pos+=(a[i]>=s);
//	cout<<pos<<'\n';
	int x=1,y=1;
	int flag=1;
	while(1){
//		cout<<y<<' '<<x<<' '<<flag<<'\n';
		pos--;
		if(pos==0){
			cout<<y<<' '<<x<<'\n';
			return ;
		}
		x=x+flag;
		if(x==n+1){
			x=n,y=y+1;
			flag=flag*(-1);
		}
		if(x==0){
			x=1,y=y+1;
			flag=flag*(-1);
		}
	}
	cout<<m<<' '<<n<<'\n';
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}

