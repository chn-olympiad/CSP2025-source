#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int T;
int n,cnt[4],ans;
struct node{
	int a1,a2,a3,max1,max2,d,pmax;
}x[N];
bool cmp(node a,node b){
	return a.d>b.d;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		cnt[1]=cnt[2]=cnt[3]=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>x[i].a1;
			x[i].max1=x[i].a1;x[i].pmax=1;
			cin>>x[i].a2;
			if(x[i].a2>x[i].max1){x[i].max2=x[i].max1;x[i].max1=x[i].a2;x[i].pmax=2;}
			else x[i].max2=x[i].a2;
			cin>>x[i].a3;
			if(x[i].a3>x[i].max1){x[i].max2=x[i].max1;x[i].max1=x[i].a3;x[i].pmax=3;}
			else if(x[i].a3>x[i].max2) x[i].max2=x[i].a3;
			x[i].d=x[i].max1-x[i].max2;
		}
		sort(x+1,x+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[x[i].pmax]<n/2){cnt[x[i].pmax]++;ans+=x[i].max1;}
			else ans+=x[i].max2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
