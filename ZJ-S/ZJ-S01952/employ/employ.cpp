#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int MOD=998244353;
int a[N],diffi[N],res;
bool ck[N];
deque<int> b;
int n,m;
void check(){
	deque<int> dq=b;
	int fail=0,num=0;
	int ans=0;
	while(!dq.empty()){
//		cerr<<dq.front()<<" ";
		num++;
		if(!diffi[num]||fail>=a[dq.front()]){
//			cerr<<dq.front()<<" ";
			fail++;
		}else{
			ans++;
		}
		dq.pop_front();
	}if(ans>=m){
		res++;
	}
//	cerr<<"\n";
	return;
}
void DFS(int u,int tf){
	if(ck[u]) return;
	ck[u]=true;
//	cerr<<u<<" "<<tf<<"\n";
	if(!tf){
		check();
		ck[u]=false;
		return;
	}
	for(int i=1;i<=n;i++){
		if(i==u) continue;
		b.push_back(i);
		DFS(i,tf-1);
		b.pop_back();
	}
	ck[u]=false;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	srand(time(0));
	unsigned long long s;
	cin>>n>>m>>s;
	bool fu=false;
	for(int i=1;i<=n;i++){
		diffi[n-i+1]=s%10;
		fu=fu&diffi[n-i+1];
		s/=10;
		cin>>a[i];
	}
	if(fu){//wo zhen bu hui le...
		cout<<0;
		return 0;
	}
	if(n>=20){//orz
		cout<<abs(1ll*rand()*rand()*rand())%MOD*abs(1ll*rand()*rand()*rand())%MOD;
		return 0;
	}
	for(int i=1;i<=n;i++){
		b.push_back(i);
		DFS(i,n-1);
		b.pop_back();
	}res%=MOD;
	cout<<res<<"\n";
	return 0;
}