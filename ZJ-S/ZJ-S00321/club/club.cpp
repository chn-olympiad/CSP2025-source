#include<bits/stdc++.h>
using namespace std;
long long t,n,a[100010][4];
struct node{
	long long num;
	int w;
}b1[100010],b2[100010],b3[100010];
bool cmp(node a,node b){
	return a.num<b.num;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int s=0,k;
		cin>>n;
		k=n/2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			if(a[i][1]==max(a[i][1],max(a[i][2],a[i][3]))){
				b1[x].w=i;
				b1[x].num=a[i][1]-max(a[i][2],a[i][3]);
				s+=a[i][1];
				x++;			
				continue;
			}
			if(a[i][2]==max(a[i][1],max(a[i][2],a[i][3]))){
				b2[y].w=i;
				b2[y].num=a[i][2]-max(a[i][1],a[i][3]);
				s+=a[i][2];
				y++;
				continue;
			}
			if(a[i][3]==max(a[i][1],max(a[i][2],a[i][3]))){
				b3[z].w=i;
				b3[z].num=a[i][3]-max(a[i][1],a[i][2]);
				s+=a[i][3];
				z++;
				continue;
			}
		}
		int m=0;
		if(x>k){
			sort(b1,b1+x,cmp);
			while(x>k){
				s-=b1[m].num;
				m++;
				x--;
			}
		}
		if(y>k){
			sort(b2,b2+y,cmp);
			while(y>k){
				s-=b2[m].num;
				m++;
				y--;
			}
		}
		if(z>k){
			sort(b3,b3+z,cmp);
			cout<<1;
			return 0;
			while(z>k){
				s-=b3[m].num;
				m++;
				z--;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}