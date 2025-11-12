#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll T,n;
const ll N=1e5+100;
string q;
ll p[N];
ll sum;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>T>>n>>q;
	
	int a,sum,s;
	for(ll i=0;i<=T;i++){
		cin>>a;
		if(a==0;)sum++;
	}
	for(int i=T-sum;i>0;i--)
		s+=i;
	sout<<sum*s;
}