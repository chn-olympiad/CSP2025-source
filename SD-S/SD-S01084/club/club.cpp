#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>inline void read(T &n);
const int N=1e5+5;
int n;
int a[N][3];
int tmp1[N],tmp2[N];
bool isA=1,isB=1;
ll ans;
int c[N];//第j列使用的次数 
void dfs(int i,ll now){
	if (i==n+1){
		ans=max(ans,now);
		return;
	}
	for (int j=0;j<3;j++){
		if (c[j]==(n>>1)) continue;
		c[j]++;
		dfs(i+1,now+a[i][j]);
		c[j]--;
	}
}
unordered_set<int>s;
int main(){
	//freopen("debug.in","r",stdin);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	read(T);
	while (T--){
		read(n);
		for (int i=1;i<=n;i++){
			read(a[i][0]),read(a[i][1]),read(a[i][2]);
			if (a[i][1]||a[i][2]) isA=0;
			if (a[i][2]) isB=0;
		}
		if (isA){
			for (int i=1;i<=n;i++) tmp1[i]=a[i][0];
			sort(tmp1+1,tmp1+n+1,greater<int>());
			for (int i=1;i<=(n>>1);i++) ans+=tmp1[i];
			cout<<ans<<'\n';
			ans=0;
		}else if (isB){
			ll ans1=0,ans2=0;
			for (int i=1;i<=n;i++) tmp1[i]=a[i][0];
			for (int i=1;i<=n;i++) tmp2[i]=a[i][1];
			sort(tmp1,tmp1+n+1,greater<int>());
			sort(tmp2,tmp2+n+1,greater<int>());
			for (int i=1;i<=(n<<1);i++){
				s.insert(tmp1[i]);
				ans1+=tmp1[i];
			}
			for (int i=1;i<=n;i++){
				if (s.count(a[i][0])==0) ans1+=a[i][1];
			}
			s.clear();
			for (int i=1;i<=(n<<1);i++){
				s.insert(tmp2[i]);
				ans2+=tmp2[i];
			}
			for (int i=1;i<=n;i++){
				if (s.count(a[i][1])==0) ans2+=a[i][0];
			}
			s.clear();
			cout<<max(ans1,ans2)<<'\n';
		}else if (n<=10){
			dfs(1,0);
			cout<<ans<<'\n';
			ans=0;
		}	
		
	}
	return 0;
}
template<typename T>inline void read(T &n){
	n=0;char c;
	T f=1;
	do{
		c=getchar();
		if (c=='-') f=-1;
	}while (c>'9'||c<'0');
	while (c>='0'&&c<='9'){
		n=(n<<1)+(n<<3)+(c^48);
		c=getchar();
	}
	n*=f;
}

