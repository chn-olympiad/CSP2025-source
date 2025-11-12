#include<bits/stdc++.h>
using namespace std;
const int N=510,Mod=998244353;
int n,m,ans;
int c[N],s[N],d[N];
vector<int>num;
bool p[N];

void dfs(int k){
	if(k<=0){
		int cnt=n;
		int d=0;
		for(int i=1;i<=num.size();i++){
			int k=num[i];
			if(d>=c[k]||s[k]==0){
				cnt--;
				d++;
			}
			if(cnt<m)break;
		}
		if(cnt>=m)ans=(ans+1)%Mod;
		return;	
	}
	for(int i=1;i<=n;i++){
		if(p[i]==1)continue;
		num.push_back(i);
		p[i]=1;
		dfs(k-1);
		p[i]=0;
		num.pop_back();
	}
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	char S;
	d[0]=0;
	for(int i=1;i<=n;i++){
		cin>>S;
		s[i]=S-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(n);
	cout<<ans%Mod;
	return 0;
}
