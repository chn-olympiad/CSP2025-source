#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
struct cl{
	int data;
	int c;//0~2
};
struct st{
	cl m[3];
	int dj;
};
int cmp(st a,st b){
	return a.dj>b.dj;
}

int t;st a[N],cleart;
int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	cin>>t;
	int n,w1,w2,w3,ans=0,c[3]={};
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>w1>>w2>>w3;
			a[i].m[0].data=w1;a[i].m[0].c=0;a[i].m[1].data=w2;a[i].m[1].c=1;a[i].m[2].data=w3;a[i].m[2].c=2;
			if(a[i].m[0].data<a[i].m[1].data){
				swap(a[i].m[0],a[i].m[1]);
			}if(a[i].m[1].data<a[i].m[2].data){
				swap(a[i].m[1],a[i].m[2]);
			}if(a[i].m[0].data<a[i].m[1].data){
				swap(a[i].m[0],a[i].m[1]);
			}
			a[i].dj=a[i].m[0].data-a[i].m[1].data;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(c[a[i].m[0].c]+1<=n/2){
				c[a[i].m[0].c]++;
				ans+=a[i].m[0].data;
			}else{
				c[a[i].m[1].c]++;
				ans+=a[i].m[1].data;
			}
			
		}
		cout<<ans<<endl;
		ans=0;
		c[0]=0;
		c[1]=0;
		c[2]=0;
		for(int i=1;i<=n;i++){
			a[i]=cleart;
		}
	}
	return 0;
}