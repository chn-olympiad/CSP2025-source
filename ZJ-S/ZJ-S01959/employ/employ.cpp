#include<bits/stdc++.h>
using namespace std;
int a[505],s[505];
int n,m,smax;
long long ans=1,p=98244353;
vector<int>ok,v;
void solve(){
//	sort(a+1,a+n+1);
	for(int i=1;i<n+1;i++){
		if(!s[i]){
			cout<<0;
			return ;
		}
	}
	for(int i=1;i<n+1;i++){
		if(a[i]<i){
			cout<<0;
			return ;
		}
		ans=(ans*(a[i]-i+1))%p;
	//	cout<<ans<<' ';
	}
	cout<<ans;
}
void solve1(){
	long long ans=0,x=0,suf=1;
	for(int i=1;i<n;i++){
		suf=(suf*i)%p;
	}
	for(int i=1;i<n+1;i++){
		if(s[i]==0) continue;
		for(int j=1;j<n+1;j++){
			if(a[j]>=i) ans++;
		}
	//	cout<<i<<' '<<ans<<"^";
	}
//	cout<<ans<<' '<<suf<<endl;
	ans=(ans*suf)%p;
	cout<<ans;
	return ;
}
int check(int x){
	int y=0;
	while(x){
		y+=x%2;
		x/=2;
	}
	return y;
}
void add(int sum){
	int point=0;
	long long x=1,zz=1;
	for(int i=1;i<=n-sum;i++) zz=(zz*i)%p;
	for(int j=0;j<v.size();j++){
		while(ok[point+1]<=v[j] && point<smax-1) point++;
		if(ok[point]>v[j] || point<j){
			x=0;
			break;
		}
//		cout<<j<<' '<<x<<' '<<point<<'\n';
		x*=point-j+1;
		x%=p;
	}
	ans+=(x*zz)%p;
	ans%=p;
//	cout<<ans;
}
void dfs(int now,int sum){
	if(now==n+1){
		if(sum>=m && sum<=smax) add(sum);
		return ;
	}
	dfs(now+1,sum);
	v.push_back(a[now]);
	dfs(now+1,sum+1);
	v.pop_back();
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n+1;i++){
		char c;
		cin>>c;
		if(c=='1') s[i]=1;
	//	cin>>s[i];
		if(s[i]){
			ok.push_back(i);
			smax++;
		}
	}
	for(int i=1;i<n+1;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		solve1();
		return 0;
	}
//	cout<<smax<<' '<<n<<endl;
	if(smax==n){
	//	cout<<"&&&";
		solve();
		return 0;
	}
	ans=0;
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}
