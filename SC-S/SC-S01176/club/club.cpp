#include<bits/stdc++.h>
using namespace std;
int n,t,a[100001][4],x,y,z,s,m,mi,mp;
int ma[100001];
long long ans;
bool bk[100001],fl;
void ysh(int o){
	x-=o;
	y-=o;
	z-=o;
	ans+=o;
	return;
}
void sert(int k,int x){
	if(k==0){
		return;
	}
	for(int i=1;i<=k-1;i++){
		ma[i]=ma[i+1];
	}
	ma[k]=x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		ans=0;
		memset(bk,1,sizeof(bk));
		cin>>n;
		m=n/2;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			if(x<=y){
				if(y<=z){
					ysh(y);
				}else{
					if(x>=z){
						ysh(x);
					}else{
						ysh(z);
					}
				}
			}else{
				if(y>=z){
					ysh(y);
				}else{
					if(x>=z){
						ysh(z);
					}else{
						ysh(x);
					}
				}
			}
			a[i][1]=x;
			a[i][2]=y;
			a[i][3]=z;
		}
		for(int i=1;i<=3;i++){
			s=0;
			fl=1;
			memset(ma,0,sizeof(ma));
			for(int j=1;j<=n;j++){
				if(a[j][i]>0){
					//cout<<"aji="<<a[j][i]<<endl;
					if(s<m){
						s++;
						ma[s]=a[j][i];
					}else{
						int k=0;
						while(a[j][i]>ma[k+1]){
							k++;
							if(k==s) break;
						}
						//cout<<"aji="<<a[j][i]<<" k="<<k<<endl;
						sert(k,a[j][i]);
					}
					//cout<<endl;
					if(s==m and fl){
						fl=0;
						sort(ma+1,ma+1+s);
					}
				}
			}
			for(int i=1;i<=s;i++){
				ans+=ma[i];
				//cout<<ma[i]<<" ";
			}
			//cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}