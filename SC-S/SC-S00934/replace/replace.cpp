#include<bits/stdc++.h>
using namespace std;
char s[505];
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)
		cin>>c[i];
	do{
		int cnt=0;	//落榜人数
		bool f=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[i]||s[i]!='1')
				cnt++;
			if(n-cnt<m){
				f=1;
				break; 
			}
		} 
		if(f==0){
			ans++;
		}
	}while(next_permutation(c+1,c+n+1));
	cout<<ans;
	return 0;
}
