#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int a,c,b,id;
}q1[N],q2[N];
int T,n,a,b,ans,vis;
bool cmp1(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	return x.b>y.b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>q1[i].a>>q1[i].b>>q1[i].c;
	
		sort(q1+1,q1+1+n,cmp1);
		for(int i=1;i<=n/2;i++){
			ans+=q1[i].a;
		}
		cout<<ans<<'\n'; 
		
	}
} 
