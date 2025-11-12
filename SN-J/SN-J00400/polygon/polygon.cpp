//Code Originally Designed by Zhang Aoyi, SN-J00400, Shaanxi NOI CSP-J/S 2025
//Lang: C++, Examination Time: 08:30~12:00
//School: Xi'an Aerospace City No.1 (Junior) High School
//Examination Place: NPU Chang'an Campus
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ld long double
using namespace std;
//priority_queue<int>q;
//priority_queue<int,vector<int>,greater<int> >qq;
//polygen
int n;
int a[5500]; 
ll ans=0;
const int Mod=998244353;
void dfs(int st,int m,int sum,int maxx){
	if(m>n||st>n+1) return;
	if((m>=3)&&(sum>2*maxx)){
		ans++;
		//cout<<st<<" "<<m<<" "<<sum<<" "<<maxx<<" "<<"\n";
		if(ans==Mod) ans=0;
	}
	for(int i=st;i<=n;i++){
		int ts=sum+a[i],tm=max(maxx,a[i]);
		dfs(i+1,m+1,ts,tm);
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	//ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(max(a[1],a[2]),a[3])){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	sort(a+1,a+1+n); 
	for(int i=1;i<=n;i++){
		dfs(i,0,0,0);
	}
	cout<<ans;
	return 0;
}

