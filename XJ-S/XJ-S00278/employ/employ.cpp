#include<bits/stdc++.h>
using namespace std;

int n,m,c[1000],a[1000],ans=0;
char s[1000];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>(s+1);
	for(int i=1;i<=n;++i)cin>>c[i];
	for(int i=1;i<=n;++i)a[i]=i;
	do{
		int cnt=0,sum=0;
		for(int i=1;i<=n;++i){
			if(cnt<c[a[i]]&&s[i]=='1')++sum;
			else ++cnt;
		}
		if(sum>=m)++ans;
	}
	while(next_permutation(a+1,a+n+1));
	cout<<ans;
	return 0;
}
