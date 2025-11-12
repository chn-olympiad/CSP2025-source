#include<bits/stdc++.h>
using namespace std;
int n,w1,w2,w3,t,ans;
struct people{
	int a,b,c;
}peo[10005];
bool cmp(people p1,people p2){
	if(p1.a==p2.a) return p1.b>p2.b;
	else if(p1.b==p2.b) return p1.c>p2.c;
	return p1.a>p2.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int flag=1;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>peo[i].a>>peo[i].b>>peo[i].c;
			if(peo[i].b!=0&&peo[i].c!=0){
				flag=0;
			}
		}
		sort(peo+1,peo+n+1,cmp);
		if(flag){
			int i=1;
			while(w1<=n/2){
				ans+=peo[i++].a;
			}
			cout<<ans<<endl;
			continue;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			if(w1>n/2){
				if(w2>n/2){
					w3++;
					ans+=peo[i].c;
				}
				else{
					w2++;
					ans+=peo[i].b;
				}
			}
			else{
				w1++;
				ans+=peo[i].a;
			}
		}
		cout<<ans<<endl;
		w1=0;w2=0;w3=0;
	}
	return 0;
}
