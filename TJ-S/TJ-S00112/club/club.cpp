#include<bits/stdc++.h>
using namespace std;
/*
1
4
4 2 1
3 2 4
5 3 4
3 5 1
*/
struct node{
	int a[7];
}peo[100005];
int n,t,sum=0;
int b[3];
int p[4];
bool cmp(node i,node j){
	if(i.a[1]>j.a[1]){
		return i.a[1]>j.a[1];
	}
	else if(i.a[2]!=j.a[2]){
		return i.a[2]>j.a[2];
	}
	else{
		return i.a[3]>j.a[3];
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for (int x=1;x<=n;x++){
			cin>>peo[x].a[1]>>peo[x].a[2]>>peo[x].a[3];
		}
		sort(peo+1,peo+n+1,cmp);
		for (int x=1;x<=n;x++){
			b[0]=peo[x].a[1];
			b[1]=peo[x].a[2];
			b[2]=peo[x].a[3];
			int q,w,e,r,y;
			r=max(b[1],b[2]);
			y=min(b[1],b[2]);
			q=max(r,b[0]);
			e=min(y,b[0]);
			w=b[0]+b[1]+b[2]-q-e;
			b[0]=e;
			b[1]=w;
			b[2]=q;
			for (int i=0;i<3;i++){
				for (int j=1;j<=3;j++){
					if(b[i]==peo[x].a[j]){
						peo[x].a[i+4]=j;
					}
				}
			}
			if(p[peo[x].a[6]]<=n/2){
				p[peo[x].a[6]]++;
				sum+=peo[x].a[peo[x].a[6]];
			}
			else{
				p[peo[x].a[5]]++;
				sum+=peo[x].a[peo[x].a[5]];
			}
		}
		cout<<sum<<endl;
		sum=0;
	}
	return 0;
} 
