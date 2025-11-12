#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
string s;
int c[1000086];
ll f(int x){
	if(x==1||x==0)return 1;
	return x*f(x-1);
}
void solve1(){
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			cout<<0;return;
		}
	}
	cout<<f(n);return;
}
void solve2(){
	
}
int b[20];int v[20];int sum,cry,num;
void so(){
	sum=0;cry=0;
	for(int i=1;i<=n;i++){
		if(cry>=c[b[i]]){
			cry++;continue;
		}
		if(s[i-1]=='0'){
			cry+=1;
		}
		else{
			sum++;
		}
	}
	if(sum>=m){
		num++;
	}
}
void solve3(int s1){
	if(s1>n){
		so();return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			b[s1]=i;
			solve3(s1+1);
			v[i]=0;
		}
	}
}
int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n==m){
		solve1();return 0;
	}
	if(m==1){
		solve2();return 0;
	}
	if(n<=18){
		solve3(1);cout<<num;return 0;
	}
	cout<<f(n);
	return 0;
}