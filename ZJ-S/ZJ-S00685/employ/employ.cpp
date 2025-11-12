#include<bits/stdc++.h>
using namespace std;
const int N=15;
char s[N];
int c[N];
int p[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int mul=1;
	for(int i=2;i<=n;i++) mul*=i;
	int tmp=0;
	for(int i=1;i<=mul;i++){
		int cnt=0;
		int ans=0;
		for(int j=1;j<=n;j++){
			if(s[j]=='0' || cnt>=c[p[j]]){
				cnt++;
			}else{
				ans++;
			}
		}
		if(ans>=m) tmp++;
		next_permutation(p+1,p+n+1);
	}
	cout<<tmp;
	return 0;
}
