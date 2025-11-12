#include<bits/stdc++.h>
using namespace std;
struct node{
	int shu,club;
};
int T,n,c1,c2,c3;
long long sum;
int a[100100][5];
node b[100100],c[100100];
int max1(int x,int y,int z,int i){
	if(x>y){
		if(x>z){
			b[i].club=1;
			return x;
		}
		else{
			b[i].club=3;
			return z;
		}
	}
	else{
		if(y>z){
			b[i].club=2;
			return y;
		}
		else{
			b[i].club=3;
			return z;
		}
	}
	return 0;
}
int max2(int x,int y,int z,int xx,int i){
	if(x==xx){
		if(y>z){
			c[i].club=1;
			return y;
		}
		else{
			c[i].club=1;
			return z;
		}
	}
	if(y==xx){
		if(x>z){
			c[i].club=2;
			return x;
		}
		else{
			c[i].club=2;
			return z;
		}
	}
	if(x>y){
		c[i].club=3;
		return x;
	}
	else{
		c[i].club=3;
		return y;
	}
}
bool cmp(node aa,node bb){
	return aa.shu<bb.shu;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--)
	{
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		c1=c2=c3=0;
		sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
			b[i].shu=max1(a[i][1],a[i][2],a[i][3],i);
			int t=max2(a[i][1],a[i][2],a[i][3],b[i].shu,i);
			c[i].shu=b[i].shu-t;
		}
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			sum+=b[i].shu;
			if(b[i].club==1){
				c1++;
			}
			else if(b[i].club==2){
				c2++;
			}
			else{
				c3++;
			}
		}
		if(c1<=n/2&&c2<=n/2&&c3<=n/2){
			cout<<sum<<"\n";
			continue;
		}
		int cha=0,qjj=0;
		if(c1>n/2) qjj=1,cha=c1-n/2;
		if(c2>n/2) qjj=2,cha=c2-n/2;
		if(c3>n/2) qjj=3,cha=c3-n/2;
		for(int i=1;i<=n;i++){
			if(c[i].club==qjj){
				sum-=c[i].shu;
				cha--;
				if(cha==0) break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
