//汤佳忆  SN-S00442  西安辅轮中学
#include<bits/stdc++.h>
using namespace std;
int n,a[100001],m,sum;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if(n==m){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool cmp=true;
	for(int i=1;i<=n;i++){
		if(i==0&&cmp==true) continue;
		if(i==0)continue;
		if(i!=0){
			cmp=false;
		}
		sum++;
		for(int j=i+1;j<=n;j++){
			s[j]--;
		}
	}
	if(sum>=m){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
