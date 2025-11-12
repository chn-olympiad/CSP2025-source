#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
struct node{
	int a,b,c;
	int mx,id;
	friend bool operator<(const node a,const node b){
		return a.mx>b.mx;
	}
}l[N];
struct mode{
	int num1,num2;
	friend bool operator<(const mode a,const mode b){
		return min(a.num1,a.num2)<min(b.num1,b.num2);
	}
}sum[N];
int t1[N],t2[N],t3[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>l[i].a>>l[i].b>>l[i].c;
			if(l[i].a>=l[i].b&&l[i].a>=l[i].c){
				l[i].mx=l[i].a;
				l[i].id=1;
			}else if(l[i].b>=l[i].a&&l[i].b>=l[i].c){
				l[i].mx=l[i].b;
				l[i].id=2;
			}else{
				l[i].mx=l[i].c;
				l[i].id=3;
			}
		}
		sort(l+1,l+1+n);
		int x=0,y=0,z=0,ans=0;
		for(int i=1;i<=n;i++){
			ans+=l[i].mx;
			if(l[i].id==1){
				x++;
				t1[x]=i;
			}else if(l[i].id==2){
				y++;
				t2[y]=i;
			}else{
				z++;
				t3[z]=i;
			}
		}
		if(x>n/2){
			for(int i=1;i<=x;i++){
				sum[i].num1=l[t1[i]].a-l[t1[i]].b;
				sum[i].num2=l[t1[i]].a-l[t1[i]].c;	
			}
			sort(sum+1,sum+1+x);
			for(int i=1;i<=x;i++){
				if(x<=n/2){
					break;
				}
				if(sum[i].num1<=sum[i].num2&&y<n/2){
					y++;
					ans-=sum[i].num1;
				}else if(sum[i].num1>sum[i].num2&&z<n/2){
					z++;
					ans-=sum[i].num2;
				}else{
					if(y>=n/2){
						z++;
						ans-=sum[i].num2;
					}else{
						y++;
						ans-=sum[i].num1;
					}
				}
				x--;
			}
		}else if(y>n/2){
			for(int i=1;i<=y;i++){
				sum[i].num1=l[t2[i]].b-l[t2[i]].a;
				sum[i].num2=l[t2[i]].b-l[t2[i]].c;	
			}
			sort(sum+1,sum+1+y);
			for(int i=1;i<=y;i++){
				if(y<=n/2){
					break;
				}
				if(sum[i].num1<=sum[i].num2&&x<n/2){
					x++;
					ans-=sum[i].num1;
				}else if(sum[i].num1>sum[i].num2&&z<n/2){
					z++;
					ans-=sum[i].num2;
				}else{
					if(y>=n/2){
						z++;
						ans-=sum[i].num2;
					}else{
						x++;
						ans-=sum[i].num1;
					}
				}
				y--;
			}
		}else if(z>n/2){
			for(int i=1;i<=z;i++){
				sum[i].num1=l[t3[i]].c-l[t3[i]].a;
				sum[i].num2=l[t3[i]].c-l[t3[i]].b;	
			}
			sort(sum+1,sum+1+z);
			for(int i=1;i<=z;i++){
				if(z<=n/2){
					break;
				}
				if(sum[i].num1<=sum[i].num2&&x<n/2){
					x++;
					ans-=sum[i].num1;
				}else if(sum[i].num1>sum[i].num2&&y<n/2){
					y++;
					ans-=sum[i].num2;
				}else{
					if(x>=n/2){
						y++;
						ans-=sum[i].num2;
					}else{
						x++;
						ans-=sum[i].num1;
					}
				}
				z--;
			}
		}
		cout<<ans<<endl;
	}
	return 0; 
}
