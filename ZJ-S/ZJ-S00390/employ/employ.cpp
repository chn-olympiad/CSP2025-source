#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[505],p[15];string s;
int check(){
	int tot=0;
	for(int i=1;i<=n;i++){
		if(i-1-tot<c[p[i]]&&s[i-1]=='1')tot++;
	}
	return tot;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10){
		for(int i=1;i<=n;i++)p[i]=i;
		int cnt=0;
		do{
			if(check()>=m)cnt++;
		}while(next_permutation(p+1,p+n+1));
		cout<<cnt;exit(0);
	}
	cout<<0;
	return 0;
}

