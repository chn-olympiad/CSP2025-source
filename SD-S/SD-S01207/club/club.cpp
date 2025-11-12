#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,t;
struct node{
	int h1,h2,h3,vis;
}a[N];
struct node2{
	int val,id,maxi;
}change[N];
bool cmp(node a,node b){
	return (a.h1-a.h2)>(b.h1-b.h2);
}
bool cmp2(node2 i,node2 j){
	return i.maxi>j.maxi;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].h1>>a[i].h2>>a[i].h3;
			a[i].vis=0;
		}
		sort(a+1,a+n+1,cmp);		
		int cnt=0;
		for(int i=1;i<=n/2;i++){
			if(a[i].h1<a[i].h3){
				change[++cnt].val=a[i].h3;
				change[cnt].id=i;
				change[cnt].maxi=a[i].h3-a[i].h1;
				a[i].vis=1;
			}
		}
		for(int i=n/2+1;i<=n;i++){
			if(a[i].h2<a[i].h3){
				change[++cnt].val=a[i].h3;
				change[cnt].id=i;
				change[cnt].maxi=a[i].h3-a[i].h2;
				a[i].vis=1;
			}
		}
		int ans=0;
		if(cnt>n/2){
			sort(change+1,change+1+n,cmp2);
			for(int i=1;i<=n/2;i++) ans+=change[i].val;			
			for(int i=n/2+1;i<=cnt;i++) a[change[i].id].vis=0;	
			for(int i=1;i<=n;i++){
				if(a[i].vis==0) ans+=max(a[i].h1,a[i].h2);
			}
					
		}else{
			for(int i=1;i<=cnt;i++) ans+=change[i].val;
			for(int i=1;i<=n/2;i++){
				if(a[i].vis==0) ans+=a[i].h1;
			}
			for(int i=n/2+1;i<=n;i++){
				if(a[i].vis==0) ans+=a[i].h2;
			}
		}
		

		cout<<ans<<endl;
	}

	return 0;
}
