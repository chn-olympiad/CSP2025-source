#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<algorithm>
#include<cmath>
using namespace std;
struct e{
	int a;
	int aa;
	int aaa;
	int ch;
	int ma1;
	int ma2;
	int id;
}h[100005];
int b[100005],c[100005],d[100005],e[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int d1=0,d2=0,d3=0,ans=0;
		for(int i=1;i<=n;i++){
			h[i].a=h[i].aa=h[i].aaa=h[i].ch=h[i].ma1=h[i].ma2=h[i].id=0;
			b[i]=c[i]=d[i]=e[i]=0;
		}
		for(int i=1;i<=n;i++){
			cin>>h[i].a>>h[i].aa>>h[i].aaa;
			h[i].id=i;
			int bb[5];
			bb[0]=bb[1]=bb[2]=bb[3]=bb[4]=0;
			bb[0]=h[i].a;
			bb[1]=h[i].aa;
			bb[2]=h[i].aaa;
			sort(bb,bb+3);
			h[i].ma1=bb[2];
			h[i].ma2=bb[1];
			h[i].ch=bb[2]-bb[1];
			//cout<<bb[0]<<" "<<bb[1]<<" "<<bb[2]<<" "<<33<<endl;
			if(h[i].ma1==h[i].a){
				b[++d1]=i;
				ans+=h[i].a;
			}
			else if(h[i].ma1==h[i].aa){
				c[++d2]=i;
				ans+=h[i].aa;
			}
			else{
				d[++d3]=i;
				ans+=h[i].aaa;
			}
			//cout<<ans<<endl;
		}
		//cout<<ans<<endl;
		if(d1>n/2){
			for(int i=1;i<=d1;i++){
				e[i]=h[b[i]].ch;
			}
			sort(e+1,e+1+d1);
			for(int i=1;i<=d1-n/2;i++){
				ans-=e[i];
			}
			//cout<<ans<<endl;
		} 
		else if(d2>n/2){
			for(int i=1;i<=d2;i++){
				e[i]=h[c[i]].ch;
			}
			sort(e+1,e+1+d2);
			for(int i=1;i<=d2-n/2;i++){
				ans-=e[i];
			}
			//cout<<ans<<endl;
		} 
		else if(d3>n/2){
			for(int i=1;i<=d3;i++){
				e[i]=h[d[i]].ch;
			}
			sort(e+1,e+1+d3);
			for(int i=1;i<=d3-n/2;i++){
				ans-=e[i];
			}
			//cout<<ans<<endl;
		} 
		cout<<ans<<endl;
	}
	return 0;
}

