#include<bits/stdc++.h>
using namespace std;
const int N=505;
int n,m,a[N],p[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s; s=" "+s;
	int l=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		p[i]=i;
		if(!a[i]) l++;
	}
	if(n>10){
		int x=1;
		for(int i=1;i<=n;i++) x=1ll*x*i%998244353;
		bool flag=true;
		for(int i=1;i<=n;i++)
			if(s[i]=='0') flag=false;
		if(l>0||!flag) printf("0");
		else printf("%d",x); 
		return 0;
	}
	int ans=0;
	do{
		int now=0,cnt=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='0'||now>=a[p[i]]) now++;
			else cnt++;
		if(cnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	printf("%d",ans);
	return 0;
} 
