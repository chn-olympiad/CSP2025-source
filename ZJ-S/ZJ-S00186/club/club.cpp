#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
struct no{
	int a[4],x;
}a[N];
struct shit{
	int x,y;
}b[N],c[N];
int T,n,i,j,ma,m2,t,w,s,k,l,u,v;
bool cmp(shit a,shit b){return a.y>b.y;}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)
			for(j=1;j<=3;j++)
				cin>>a[i].a[j];
		s=0;
		for(i=1;i<=n/2;i++){
			s+=a[i].a[1];
			a[i].x=1;
		}
		for(i=n/2+1;i<=n;i++){
			s+=a[i].a[2];
			a[i].x=2;
		}
		for(i=n+1;i<=n/2+n;i++)
			a[i].a[1]=a[i].a[2]=a[i].a[3]=0,a[i].x=3;
		n=n/2+n;
		
//		cout<<s<<"\n";
		int fl=1;
		while(fl==1){
//		for(int cnm=1;cnm<=3;cnm++){
			fl=0;
			for(k=1;k<=3;k++)
				for(l=k+1;l<=3;l++){
					u=v=0;
					for(i=1;i<=n;i++)
						if(a[i].x==k)
							b[++u].x=i,b[u].y=a[i].a[l]-a[i].a[k];
					for(i=1;i<=n;i++)
						if(a[i].x==l)
							c[++v].x=i,c[v].y=a[i].a[k]-a[i].a[l];
					sort(b+1,b+1+u,cmp);
					sort(c+1,c+1+v,cmp);
					t=1;w=1;
					while(t<=u&&w<=v){
						if(b[t].y+c[w].y>0){
							fl=1;
							s+=b[t].y+c[w].y;
							swap(a[b[t].x].x,a[c[w].x].x);
	//						cout<<b[t].x<<" "<<c[w].x<<"\n";
							t++;w++;
						}
						else break;
					}
				}
		}
		
		cout<<s<<"\n";
//		cout<<"\n";
	}
	return 0;
}
/*
3 
4 
4 2 1
3 2 4
5 3 4
3 5 1
4 
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/
