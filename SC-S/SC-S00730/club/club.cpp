#include<bits/stdc++.h>
using namespace std;
int b[100002];
int c[100002];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int q=1;q<=t;q++){
		int n;
		cin>>n;
		int m[100005][4],a[100002];
		int b1=0,c1=0,a2=0,b2=0,a1=0,c2=0,ant=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>m[i][j];
			}
			if(m[i][1]>=m[i][3]&&m[i][1]>=m[i][2]){
				a[a2+1]=i;
				a1++;
				a2++;
			}else if(m[i][2]>=m[i][1]&&m[i][2]>=m[i][3]){
				b[b2+1]=i;
				b1++;
				b2++;
			}else{
				c[c2+1]=i;
				c1++;
				c2++;
			}
		}
		if(a1>n/2){
			for(int o=1;o<=a1-n/2;o++){
				int x=1000000,y;
				for(int i=1;i<=a2;i++){
					if(m[a[i]][1]-max(m[a[i]][2],m[a[i]][3])<x){
						x=m[a[i]][1]-max(m[a[i]][2],m[a[i]][3]);
						y=i;
					}
				}
				if(m[a[y]][2]>=m[a[y]][3]){
					b[b2++]=a[y];
					b2++;
					b1++;
				}else{
					c[c2++]=a[y];
					c2++;
					c1++;
				}
				a[y]=0;
			}
		}else if(b1>n/2){
			for(int o=1;o<=b1-n/2;o++){
				int x=1000000,y;
				for(int i=1;i<=b2;i++){
					if(m[b[i]][2]-max(m[b[i]][1],m[b[i]][3])<x){
						x=m[b[i]][2]-max(m[b[i]][1],m[b[i]][3]);
						y=i;
					}
				}
				if(m[b[y]][1]>=m[b[y]][3]){
					a[a2++]=b[y];
					a2++;
					a1++;
				}else{
					c[c2++]=b[y];
					c2++;
					c1++;
				}
				b[y]=0;
			}
		}else if(c1>n/2){
			for(int o=1;o<=a1-n/2;o++){
				int x=1000000,y;
				for(int i=1;i<=c2;i++){
					if(m[c[i]][3]-max(m[c[i]][2],m[c[i]][1])<x){
						x=m[c[i]][3]-max(m[c[i]][2],m[c[i]][1]);
						y=i;
					}
				}
				if(m[c[y]][2]>=m[c[y]][1]){
					b[b2++]=c[y];
					b2++;
					b1++;
				}else{
					a[c2++]=c[y];
					a2++;
					a1++;
				}
				c[y]=0;
			}
		}
		for(int i=1;i<=a2;i++){
			ant+=m[a[i]][1];
		}
		for(int i=1;i<=b2;i++){
			ant+=m[b[i]][2];
		}
		for(int i=1;i<=c2;i++){
			ant+=m[c[i]][3];
		}
		cout<<ant<<endl;
	}
	return 0;
} 