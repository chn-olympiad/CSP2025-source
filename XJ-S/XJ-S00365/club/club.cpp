#include<bits/stdc++.h> 
using namespace std;
struct stu{
	int i,j,k;
}a[100005];
bool cmp(stu x,stu y){
	int a=max(x.i,max(x.j,x.k));
	int b=max(y.i,max(y.j,y.k));
	if(a!=b) return a>b;
	else{
		int c=min(x.i,max(x.j,x.k));
		int d=min(y.i,max(y.j,y.k));
		if(c!=d) return c>d;
		else{
			int e=min(x.i,min(x.j,x.k));
			int f=min(y.i,min(y.j,y.k));
			return e>f;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n,x=0,y=0,z=0,sum=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].i>>a[i].j>>a[i].k;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			int q=max(a[i].i,max(a[i].j,a[i].k));
			if(q==a[i].i&&x<n/2){
				x++;
				sum+=q; 
			}
			else if(q==a[i].j&&y<n/2){
				y++;
				sum+=q; 
			}
			else if(q==a[i].k&&z<n/2){
				z++;
				sum+=q;
			}
			else{
				int w=min(a[i].i,max(a[i].j,a[i].k));
				if(w==a[i].i&&x<n/2){
					x++;
					sum+=w; 
				}
				else if(w==a[i].j&&y<n/2){
					y++;
					sum+=w; 
				}
				else if(w==a[i].k&&z<n/2){
					z++;
					sum+=w;
				}
			}
		}
		cout<<sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
