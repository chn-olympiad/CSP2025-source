#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}my[100010];
int ans;
int s[3000010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<3*n;i++){
			cin>>s[i];
		}
		sort(s,s+n+1);
		for(int i=n;i>0;i++)	ans+=s[i];
		cout<<ans;
	}	
	return 0;
}
