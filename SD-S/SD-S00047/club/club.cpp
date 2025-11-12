#include<bits/stdc++.h>
using namespace std;
struct node{
	int b[4];
	int c,m;
};
node a[100009];
int t;
long long s; 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int n;
		s=0;
		int f[4]={0},mi[4][100009]={};
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3];
			if(a[i].b[1]>a[i].b[2]&&a[i].b[1]>a[i].b[3]){
				a[i].m=1;
				if(a[i].b[2]>a[i].b[3])a[i].c=a[i].b[1]-a[i].b[2];
				else a[i].c=a[i].b[1]-a[i].b[3];
			}
			else if(a[i].b[2]>a[i].b[1]&&a[i].b[2]>a[i].b[3]){
				a[i].m=2;
				if(a[i].b[1]>a[i].b[3])a[i].c=a[i].b[2]-a[i].b[1];
				else a[i].c=a[i].b[2]-a[i].b[3];
			}
			else {
				a[i].m=3;
				if(a[i].b[2]>a[i].b[1])a[i].c=a[i].b[3]-a[i].b[2];
				else a[i].c=a[i].b[3]-a[i].b[1];	
			}
			s+=a[i].b[a[i].m];
			f[a[i].m]++;
			mi[a[i].m][f[a[i].m]]=a[i].c;
		}
		for(int i=1;i<=3;i++){
			if(f[i]<=n/2)continue;
			int k=f[i]-n/2;
			int h=1;
			while(k--){
				int l=h;
				for(int j=h+1;j<=f[i];j++){
					if(mi[i][l]>mi[i][j])l=j;
				}
				s=s-mi[i][l];
				swap(mi[i][h],mi[i][l]);
				h++;
			}
		}
		cout<<s<<endl;
	}
	return 0;
}

