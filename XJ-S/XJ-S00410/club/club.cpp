#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+10;
int sum_cnt=0;
int x,y,z;
int sum=0;
int x1[maxn],yx[maxn],z1[maxn];
bool cmp(int aa,int bb){
	return aa>bb;
}
struct node{
	int a,b,c;
	int id;
}a[maxn];
int n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		int l1=0,l2=0,l3=0;
		for(int i=1;i<=n;i++){
			sum_cnt=0;
			cin>>a[i].a>>a[i].b>>a[i].c;
			a[i].id=max(a[i].a,max(a[i].b,a[i].c));
			//cout<<a[i].id<<endl;
			if(a[i].id==a[i].a){
				x++;
				l1++;
				x1[l1]=a[i].id;
			}else if(a[i].id==a[i].b){
				y++;
				l2++;
				yx[l2]=a[i].id;
			}else{
				z++;
				l3++;
				z1[l3]=a[i].id;
			}
		}
		//cout<<x<<"x "<<y<<"y "<<z<<"z"<<endl;
		
			sum=0;
		if(x>n/2){
			//cout<<x<<endl;
			sort(x1+1,x1+1+l1,cmp);
			/*
			for(int i=1;i<=l1;i++){
			cout<<x1[i]<<" ";
			}*/
			for(int i=n/2+1;i<=l1;i++){
				x--;y++;
				for(int j=1;j<=n;j++){
					if(a[j].a==x1[i])
					{
						yx[y]=max(a[j].b,a[j].c);
					}
				}
			}
			for(int i=1;i<=n/2;i++){
				sum_cnt+=x1[i];
			}
			sum_cnt+=sum;
			
		}else{
			//cout<<x<<endl;;
			for(int i=1;i<=l1;i++){
				sum_cnt+=x1[i];
			}
			
			
		}
		if(y>n/2){
			sort(yx+1,yx+1+l2,cmp);
			for(int i=n/2+1;i<=l2;i++){
				y--;z++;
				for(int j=1;j<=n;j++){
					if(a[j].b==yx[i])
					{
						z1[z]=max(a[j].a,a[j].c);
					}
				}
			}
			for(int i=1;i<=n/2;i++){
				sum_cnt+yx[i];
			}
			sum_cnt+=sum;
			
		}else {
			//cout<<y<<endl;
			for(int i=1;i<=y;i++){
				sum_cnt+=yx[i];
			}
			
			
		}
		
		if(z>n/2){
			sort(z1+1,z1+1+l2,cmp);
			for(int i=1;i<=n/2;i++){
				sum_cnt+=z1[i];
			}
			sum_cnt+=sum;
		}else{
			for(int i=n/2+1;i<=l2;i++){
				x++,z--;
				for(int j=1;j<=n;j++){
					if(a[j].c==z1[i])
					{
						z1[z]=max(a[j].a,a[j].b);
					}
				}
			}
			for(int i=1;i<=z;i++){
				sum_cnt+=z1[i];
			}
			
			
		}
		
		cout<<sum_cnt<<endl;
	}
	
	return 0;
}
/*
1
5
4 2 1
3 2 4
5 3 4
3 5 1
5 1 1


2 2 1
5
10 
*/
