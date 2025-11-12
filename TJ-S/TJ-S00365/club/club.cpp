#include<bits/stdc++.h>
using namespace std;
long long n,t,ff,fff,fff1,ans,bb;
int cmp(int q,int w){
	return q>w;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
cin>>t;
while(t--){
cin>>n;
long long a[10005][3]={0},b[10005][3]={0},d[10005]={0},e[10005]={0},f[10005]={0},c[10005][3]={0};
	ans=0;
	ff=0;
	fff=0;
	fff1=0;
	bb=0;
	
	for(int h=0;h<n;h++){
		for(int l=0;l<3;l++){
			cin>>a[h][l];
			if(l==0){
				d[h]=a[h][0];
			}
			if(l==1){
				e[h]=a[h][1];
			}
			if(l==2){
				f[h]=a[h][2];
			}
			if(n>0){
				b[h-1][l]=a[h-1][l]-a[h][l];
//				cout<<b[h-1][l]<<" ";
			}
		}
	}
	sort(d,d+n,cmp);
	sort(e,e+n,cmp);
	sort(f,f+n,cmp);
	ff=n/2;
	int aa=0;
	for(int i=0;i<ff;i++){
		ans+=d[i];
	for(int h=0;h<n;h++){
	if(a[h][0]==d[i]&&aa<ff){
		c[h][0]=1;
		fff=h+1;
		aa++;
		
	}
	}
}
//1
//for(int i=0;i<n;i++){
//		for(int j=0;j<3;j++){	
//	cout<<c[i][j]<<" "; 
//} 
//cout<<endl;
//}

int i=0;
	for(int h=0;h<n;h++){
	if(a[h][1]==e[i]){
		if(b[h][1]>b[h][0]&&c[h][0]==1){
		
			ans+=a[h][1];
			ans-=a[h][0];
			c[h][0]=0;
			c[h][1]=1;
			ans+=a[fff][0];
			c[fff][0]=1;
		}
		else{
			if(bb==ff){
				break;
			}
			else{
				if(c[h][0]==1){
					break;
				}
				else{
			bb++;
			c[h][1]=1;
			fff1=h+1;	
			ans+=a[h][1];
			i++;
			}
		}
		}
	}
	}
int r=0;
	for(int h=0;h<n;h++){
	if(a[h][2]==f[r]){
		if(b[h][2]>b[h][1]&&c[h][1]==1){
			ans+=a[h][2];
			ans-=a[h][1];
			c[h][1]=0;
			c[h][2]=1;
			ans+=a[fff1][1];
			c[fff1][1]=1;
		}
		else{
			if(bb==ff){
				break;
			}
			else{
				if(c[h][1]==1){
					break;
				}
				else{
				
				bb++;
			c[h][2]=1;	
			ans+=a[h][2];
			r++;
			}
		}
		}
	}
	}
	cout<<ans<<endl;
}
	return 0;
} 
