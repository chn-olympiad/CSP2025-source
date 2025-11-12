#include<bits/stdc++.h>
using namespace std;

int t,n,k,sum,c[4];

struct node{
	int size;
	int num;
}x[4];

struct node1{
	int num;
	int club;
	int h;
}a[120000];

bool cmp(node x1,node y1){
	return x1.num>y1.num;
}

bool cmp1(node1 x1,node1 y1){
	return x1.h<y1.h;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		c[1]=c[2]=c[3]=sum=k=0;
		cin>>n;
		for(int i=1;i<=n;i++) {
			x[1].size=1;x[2].size=2;x[3].size=3;
			scanf("%d%d%d",&x[1].num,&x[2].num,&x[3].num);
			sort(x+1,x+4,cmp);
			sum+=x[1].num;
			a[i].club=x[1].size;a[i].num=x[1].num;a[i].h=x[1].num-x[2].num;
			c[x[1].size]++;
		}
		if(c[1]>n/2) k=1;if(c[2]>n/2) k=2;if(c[3]>n/2) k=3;
		
		if(k){
			sort(a+1,a+1+n,cmp1);
			for(int i=1;i<=n;i++){
				if(a[i].club==k){
					sum-=a[i].h;
					c[k]--;
					if(c[k]<=n/2)
					 break;
				}
			}
		}
		
		cout<<sum<<'\n';
	}
	
	return 0;
}
