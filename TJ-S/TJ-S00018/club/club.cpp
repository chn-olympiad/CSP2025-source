#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b,c,ans,arr[100005][4],f[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>arr[i][1]>>arr[i][2]>>arr[i][3];
			if(arr[i][1]>=arr[i][2] && arr[i][1]>=arr[i][3]){
				f[i]=1;
				a++;
			}
			else if(arr[i][2]>=arr[i][1] && arr[i][2]>=arr[i][3]){
				f[i]=2;
				b++;
			}
			else{
				f[i]=3;
				c++;
			}
			if(a>n/2){
				a--;
				int x=arr[i][1],y=i;
				for(int j=1;j<i;j++){
					if(arr[j][1]==x){
						if(max(arr[j][2],arr[j][3])<max(arr[y][2],arr[y][3])){
							x=arr[j][1];
							y=j;
						}
					}
					if(arr[j][1]<x){
						x=arr[j][1];
						y=j;
					}
				}
				if(arr[i][2]>=arr[i][3]){
					f[y]=2;
					b++;
				}
				else{
					f[y]=3;
					c++;
				}
			}
			if(b>n/2){
				b--;
				int x=arr[i][2],y=i;
				for(int j=1;j<i;j++){
					if(arr[j][2]==x){
						if(max(arr[j][1],arr[j][3])<max(arr[y][1],arr[y][3])){
							x=arr[j][2];
							y=j;
						}
					}
					if(arr[j][2]<x){
						x=arr[j][2];
						y=j;
					}
				}
				if(arr[i][1]>=arr[i][3]){
					f[y]=1;
					a++;
				}
				else{
					f[y]=3;
					c++;
				}
			}
			if(c>n/2){
				c--;
				int x=arr[i][3],y=i;
				for(int j=1;j<i;j++){
					if(arr[j][3]==x){
						if(max(arr[j][1],arr[j][2])<max(arr[y][1],arr[y][2])){
							x=arr[j][3];
							y=j;
						}
					}
					if(arr[j][3]<x){
						x=arr[j][3];
						y=j;
					}
				}
				if(arr[i][1]>=arr[i][2]){
					f[y]=1;
					a++;
				}
				else{
					f[y]=2;
					b++;
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			ans=ans+arr[i][f[i]];
		}
		cout<<ans<<endl;
	}
	return 0;
}
