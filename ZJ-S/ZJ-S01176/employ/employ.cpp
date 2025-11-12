#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ans;
char s[10005];
int a[100005],p[100005];
int solve(){
	int now=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='0'||now>=a[p[i]]){
			now++;
		}
		else{
			cnt++;
		}
	}
	return cnt>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),p[i]=i;
	do{
		ans+=solve();
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}

