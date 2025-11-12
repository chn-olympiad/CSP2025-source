#include<bits/stdc++.h>

using namespace std;

long long n,k,a[500001],b[500001],t;

struct stu
{
	int x,y;
};
int cmp(stu a,stu b){
	return a.x<b.x or a.x==b.x and a.y<b.y;
}

stu c[10000001],d[10000001];

int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[1];
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
		b[i]^=b[i-1];
	}

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(i!=1){
				long long p=b[j]^b[i-1];
				if(p==k){
					t++;
					c[t].x=i;
					c[t].y=j;
				}
			}else{
				if(b[j]==k){
					t++;
					c[t].x=i;
					c[t].y=j;
				}
			}
			
		}
	}
	sort(c+1,c+t+1,cmp);
	d[1].x=c[1].x;
	d[1].y=c[1].y;
	long long cnt=1;
	for(int i=2;i<=t;i++){
		long long u=cnt;
		while(1==1){
			if(u==0){
				break;
			}
			if(c[i].x>d[u].y){
				u++;
				break;
			}else{
				u--;
			}
		}
		if(u>cnt){
			d[u].x=c[i].x;
			d[u].y=c[i].y;
			cnt=u;
		}
		
	}
	cout<<cnt;
	return 0;
} 
