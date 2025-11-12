#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t=0;
	cin>>t;
	
	while(t--){
		int n=0,v=0;
		long long a[10005][3]={0};
		int p[10005][2]={0};
		cin>>n;
		v=n/2;
		int tmp[3]={0};
		int h[10005]={0};
		for(int i=0;i<n;i++){
			cin>>a[i][0]>>a[i][1]>>a[i][2];
			p[i][0]=0;
			if(a[i][0]<a[i][1] && a[i][1]>a[i][2])      p[i][0]=1, p[i][1] = a[i][0]>=a[i][2]? 0:2;
			else if(a[i][2]>a[i][1] && a[i][2]>a[i][0]) p[i][0]=2, p[i][1] = a[i][0]>=a[i][1]? 0:1;
			else p[i][1] = a[i][2]>=a[i][1]? 2:1;
			
			tmp[p[i][0]]++;
			h[i]=a[i][p[i][0]]-a[i][p[i][1]];
		}
		if(tmp[0]>v||tmp[1]>v||tmp[2]>v){
			int m=tmp[0]>tmp[1]?(tmp[0]>tmp[2]?0:2):(tmp[1]>tmp[2]?1:2);
			int t2[20005][20];
			for(int i=0;i<20005;i++) for(int j=0;j<10;j++) t2[i][j]=-1;
			for(int i=0;i<n;i++){
				if(t2[h[i]][0]!=-1){
					int o=0;
					while(t2[h[i]][o]!=-1){
						o++;
					}
					t2[h[i]][o]=i;
					continue;
				}
				
				t2[h[i]][0]=i;
			}
			int y=0,i=0;
			while(i<tmp[m]-v){
				if(t2[y][0]!=-1) {
					if(t2[y][1]==-1){
						swap(p[t2[y][0]][0],p[t2[y][0]][1]);
						i++;
						y++;
					}else if(t2[y][1]>-1){
						int o=0;
						while(t2[h[i]][o]!=-1){
							swap(p[t2[y][o]][0],p[t2[y][o]][1]);i++;
							o++;
						}
						y++;
					}
				}
				else y++;
			}
			
		}
		int c=0;
		for(int i=0;i<n;i++){
			c+=a[i][p[i][0]];
		}
		cout<<c<<"\n";
		
	}
	
	return 0;
}