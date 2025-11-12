#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],cnt=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	int p=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0) p++;
		sort(c,c+n);
	}
	int k=n-m;
	int l;
	for(int i=1;i<=k;i++){
		if(c[i]>k){
			l=i;
		}
	}
	for(int i=1;i<l;i++){
		cnt*=i;
		cnt%=998244353;
	}
	for(int i=l+1;i<n;i++){
		cnt*=i;
		cnt%=998244353;
	}
	cout<<cnt;
	return 0;
}
