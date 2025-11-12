#include<bits/stdc++.h>
using namespace std;
int n,m,c[15];string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>c[i];
	int tmp[15];
	for(int i=1;i<=n;i++){
		tmp[i]=i;
	}
	int ans=0;
	do{
		int pre=0,tmpp=0;
		for(int i=1;i<=n;i++){
			if(pre>=c[tmp[i]]){
				pre++;
				continue;
			}
			if(s[i-1]=='0')pre++;
			else tmpp++;
		}
		ans+=(tmpp>=m);
	}while(next_permutation(tmp+1,tmp+n+1));
	cout<<ans<<'\n';
	return 0;
}
