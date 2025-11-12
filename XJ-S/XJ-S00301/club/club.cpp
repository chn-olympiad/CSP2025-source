#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int m1[N],m2[N],m3[N];
struct node{
	int a,b,c;
}bm[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		long long sum=0,ap=0,bp=0,cp=0,a1=1,b1=1,c1=1;
		cin>>n;
		int flag=n/2;
		for(int i=1;i<=n;i++){
			cin>>bm[i].a>>bm[i].b>>bm[i].c;
			if(max(bm[i].c,max(bm[i].a,bm[i].b))==bm[i].a) m1[i]=bm[i].a;
			else if(max(bm[i].c,max(bm[i].a,bm[i].b))==bm[i].b) m2[i]=bm[i].b;
			else m3[i]=bm[i].c;
		}
		sort(m1+1,m1+n+1,cmp);
		sort(m2+1,m2+n+1,cmp);
		sort(m3+1,m3+n+1,cmp);
		while(1){
			sum+=m1[a1];
			a1++;
			ap++;
			if(ap==flag) break;
		}
		while(1){
			sum+=m2[b1];
			b1++;
			bp++;
			if(bp==flag) break;
		}
		while(1){
			sum+=m3[c1];
			c1++;
			cp++;
			if(cp==flag) break;
		}
		cout<<sum<<endl;
		for(int i=1;i<=n;i++){
			m1[i]=0;
			m2[i]=0;
			m3[i]=0;
			bm[i].a=0;
			bm[i].b=0;
			bm[i].c=0;
		}
	}
	return 0;
}
//Ren5Jie4Di4Ling5%
