#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z,len;
}a[100001];
int t,n;
int a1[100001],a2[100001],a3[100001];
int minx(int x,int y,int z){
	if(y>=x&&y<=z||y<=x&&y>=z){
		return y;
	}
	if(x>=y&&x<=z||x<=y&&x>=z){
		return x;
	}
	if(z<=x&&z>=y||y<=z&&y>=x){
		return z;
	}
}
bool cmp(node a,node b){
	return a.len>b.len;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0,len1=0,len2=0,len3=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			a[i].len=max(max(a[i].x,a[i].y),a[i].z)-minx(a[i].x,a[i].y,a[i].z);//求比较的值 
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
	        if(a[i].x>=a[i].y&&a[i].x>=a[i].z){
	        	if(len1<n/2){
	        		len1++;
	        		ans+=a[i].x;
				}
				else{
					if(a[i].y>a[i].z){
						len2++;
						ans+=a[i].y;
					}
					else{
					    len3++;
					    ans+=a[i].z;
					}
				}
			}
			else if(a[i].y>=a[i].x&&a[i].y>=a[i].z){
	        	if(len2<n/2){
	        		len2++;
	        		ans+=a[i].y;
				}
				else{
					if(a[i].x>a[i].z){
						len1++;
						ans+=a[i].x;
					}
					else{
					    len3++;
					    ans+=a[i].z;
					}
				}
			}
			else{
				if(len3<n/2){
	        		len3++;
	        		ans+=a[i].z;
				}
				else{
					if(a[i].y>a[i].x){
						len2++;
						ans+=a[i].y;
					}
					else{
					    len1++;
					    ans+=a[i].x;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
