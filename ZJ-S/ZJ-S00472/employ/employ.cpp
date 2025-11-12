#include<bits/stdc++.h>
using namespace std;

#define int long long
const int mod=998244353;
const int N=510;
int n,m;
char ch[N];
bool v[N];
int c[N];
int spa=0;
int bk[510];
int cnt;
vector<int>p;
bool is_prime[N];
void seiz(){
	for(int i=1;i<=509;i++)is_prime[i]=false;
	for(int i=2;i<=510;i++){
		if(!is_prime[i])p.push_back(i);
		for(int j:p){
			if(i*j>=510)break;
			is_prime[i*j]=1;
		}
	}
}

int C(int n,int m){
	int ans=1;
	for(int i=cnt;i>=1;i--){
//		cout<<"i:"<<i<<endl;
		ans*=i;
		ans%=mod;
	}
	return ans;
}

void solveA(){//C(n,m);
	cout<<C(n,m)<<endl;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(ch+1);
//	cout<<n<<' '<<m<<endl;
	seiz();
	for(int i=1;i<=n;i++){
		v[i]=ch[i]-'0';
		if(v[i])spa++;
	}
	cnt=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)cnt--;
	}
//	cout<<"spa:"<<spa<<endl;
	if(spa==n){
		solveA();
	}
}
