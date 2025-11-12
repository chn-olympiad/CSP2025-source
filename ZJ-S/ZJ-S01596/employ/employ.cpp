#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998224353;
int n,m,p[N],ans;
bool b[N];
string s;
void f(int day,int c,int sum,int x){
	if(s[day-1]=='0'||p[x]<=c){
		c++;
	}else{
		sum++;
	}
	if(day==n){
//		cout<<sum<<"\n";
		if(sum>=m){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(b[i]){
			continue;
		}
		b[i]=1;
		f(day+1,c,sum,i);
		b[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=1;
		f(1,0,0,i);
		b[i]=0;
	}
	cout<<ans;
	return 0;
}