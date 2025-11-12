#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=1e3+5,MOD=998244353,M=21,K=(1<<18)+1145;
ll jc[N],inv[N];
int f[K][M],pc[K],n;
ll qpow(ll a,int b){
	ll ans=1;a%=MOD;
	while (b){
		if (b&1) ans=ans*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ans;
}
int c[N],tot[N],sm[N];
ll A(int n,int m){//n个球选出m个（不记录顺序）的方案数
	if (n<m) return 0;
	return jc[n]*inv[n-m]%MOD;
}
ll C(int n,int m){
	if (n<m) return 0;
	return jc[n]*inv[m]%MOD*inv[n-m]%MOD;
}
string str;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int m;cin >> n >> m;
	cin >> str;
	int cnt=0;
	for (int i=0;i<n;++i) cnt+=(str[i]=='1');
	for (int i=1;i<=n;++i) cin >> c[i],++tot[c[i]];
	jc[0]=inv[0]=1;for (int i=1;i<N;++i) jc[i]=jc[i-1]*i%MOD,inv[i]=qpow(jc[i],MOD-2);
	if (m==n){
		if (tot[0]){//有0的存在
			cout<<0<<"\n";
		}else{//否则一定成功（除非s中有0）
			if (cnt==n) cout<<jc[n]<<"\n";
			else cout<<0<<"\n";
		}
	}else if (n<=18){
		f[0][0]=1;//目前面试集合是i，已经有j个人被吓跑了，的方案数
		int op=1,se=(1<<n),ans=0;
		for (int i=0;i<K;++i) pc[i]=pc[i>>1]+(i&1);
		vector<int> st;
		for (int i=0;i<se;++i) st.emplace_back(i);
		sort(st.begin(),st.end(),[](const int &a,const int &b){
			return pc[a]<pc[b];
		});
		f[0][0]=1;
		for (int &s:st){
			for (int j=0;j<=pc[s];++j){//几个人被吓跑了
				for (int k=0;k<n;++k){
					if (s>>k&1) continue;
					if (str[pc[s]]=='0' || c[k+1]<=j) (f[s^(1<<k)][j+1]+=f[s][j])%=MOD;//挂了
					else (f[s^(1<<k)][j]+=f[s][j])%=MOD;
//					cout<<s<<" "<<j<<" "<<f[s][j]<<" "<<k<<" "<<(str[pc[s]-1]=='0' || c[k+1]<=j)<<" "<<<<"\n";
				}
//				cout<<"query : "<<s<<" "<<j<<" "<<f[s][j]<<"\n";
			}
		}
		for (int i=1;i<=n;++i) if (n-i>=m) ans+=f[se-1][i];
		cout<<ans<<"\n";
	}else if (cnt==n){//如果你来，包能过的
		cout<<jc[n]<<"\n";
	}else{
		cout<<jc[n]<<"\n";
	}
	cout.flush();
	return 0;
}
//也无非汉末离乱走一遭，道说那孙刘曹
/*
怎么是记数题
有状压dp，f(i,S)
可否容斥？总体减单个
吓跑的人的个数一定是单调不降的
5 3
11111
1 2 2 0 0
Ren5Jie4Di4Ling5%
*/