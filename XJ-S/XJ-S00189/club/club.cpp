#include<bits/stdc++.h>
using namespace std;
const int N=1e5+12;
int t,n,a1[N],a2[N],a3[N];
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		bool fa=1;
		for(int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
			if(a2[j]!=0 || a3[j]!=0)fa=0;
		}
		if(fa){
			sort(a1+1,a1+n+1,cmp);
			int ans=0;
			for(int j=1;j<=n/2;j++)ans+=a1[j];
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
