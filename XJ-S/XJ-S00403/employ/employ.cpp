#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
char a[505];
int b[505];
int n,m,d;
bool flag=1;
long long num=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			flag=0;
		}
	}
	if(m==n)cout<<0;
	if(flag){
		int c=n,sum;
		for(int i=1;i<=n;i++){
			cin>>d;
			b[d]++;
		}
		if(b[0]==0){
			for(int i=1;i<=n;i++){
				num=(num*i)%mod;
			}
			cout<<num;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	return 0;
}
