#include<bits/stdc++.h>
using namespace std;
int x,y,z,n,k,m;
int sum[100005];
int a[10005],b[10005],c[10005],p[10005],q[10005];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		m=0;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>b[j]>>c[j];
			p[j]=max(a[j],b[j]);
			q[j]=max(p[j],c[j]);
			if(c[j]<p[j]){
				p[j]=c[j];
			}
			m+=q[j];
			if(q[j]==a[j]) x++;
			if(q[j]==b[j]) y++;
			if(q[j]==c[j]) z++;
			if(x<=k/2&&y<=k/2&&z<=k/2) sum[i]=m;
			else{
			for(int f=1;f<j;f++){
			if(x>y&&x>z){
					if(q[f]==a[f]) sum[i]=max(m-q[f]+p[f]+q[j],m-q[j]+p[j]);
					if(m-q[f]+p[f]+q[j]<m-q[j]+p[j]&&p[j]==b[j]){
						x--;
						y++;
					}
					else if(m-q[f]+p[f]+q[j]<m-q[j]+p[j]&&p[j]==c[j]){
						x--;
						z++;
					}
				
			}
			else if(y>x&&y>z){
					if(q[f]==b[f]) sum[i]=max(m-q[f]+p[f]+q[j],m-q[j]);
					if(m-q[f]+p[f]+q[j]<m-q[j]+p[j]&&p[j]==a[j]){
						y--;
						x++;
					}
					else if(m-q[f]+p[f]+q[j]<m-q[j]+p[j]&&p[j]==c[j]){
						y--;
						z++;
					}
				
			}
			else if(z>y&&z>x){
					if(q[f]==c[f]) sum[i]=max(m-q[f]+p[f]+q[j],m-q[j]);
					if(m-q[f]+p[f]+q[j]<m-q[j]+p[j]&&p[j]==b[j]){
						z--;
						y++;
					}
					else if(m-q[f]+p[f]+q[j]<m-q[j]+p[j]&&p[j]==a[j]){
						z--;
						x++;
					}
				
			}
			}
		}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<sum[i]<<endl;
	}
	return 0;
}
