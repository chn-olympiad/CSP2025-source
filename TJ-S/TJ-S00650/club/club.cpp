#include<bits/stdc++.h>
using namespace std;
int t;
struct score{
	int f,s,t;
}a[100005];
bool Cmp(score x,score y){
	return x.f>y.f;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,bj=0;
		int ans=0;
		cin>>n;
		for(int i=1; i<=n; i++){
			cin>>a[i].f>>a[i].s>>a[i].t;
        }
        sort(a+1,a+1+n,Cmp);
        for(int i=1; i<=n/2; i++){
        	ans+=a[i].f;
		}
		for(int i=n/2+1; i<=n; i++){
			ans+=a[i].s;
		}
		cout<<ans<<endl; 
	}
	                           
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
