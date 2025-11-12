//SN-S00158 孙悦翔 西安市曲江第一学校 
#include<bits/stdc++.h>
using namespace std;
int t,n,ansa,ansb,ansc,a[10005][3],ans,ma[10005][1],mi[10005][1],x,s,midd,cnt[5]; 
int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			ans=a[j][1]+a[j][2]+a[j][3];
			ma[j][0]=max(max(a[j][1],a[j][2]),a[j][3]);
			for(s=1;ma[s][0];s++){
				ma[j][1]=s;
			}
			if(ma[j][0]==ans){
				ma[j][0]=0;
				mi[x][1]=x;
				mi[x++][0]=ans;
			}
		}
		for(int k=1;k<x;k++){
			for(int u=k+1;u<=x;u++){
				if(mi[k]<mi[u]){
					swap(mi[k][0],mi[u][0]);
					swap(mi[k][1],mi[u][1]);
				}
			}
		}
		for(int k=1;k<x;k++){
			for(int u=k+1;u<=x;u++){
				if(ma[k]<ma[u]){
					swap(ma[k][0],ma[u][0]);
					swap(ma[k][1],ma[u][1]);
				}
			}
		}
		for(int k=1;k<=x;k++){
			if(mi[k][0]==a[mi[k][1]][1]&&ansa<n/2){
				ansa++;
				cnt[i-1]+=mi[k][0];
			}
			else if(mi[k][0]==a[mi[k][1]][1]&&ansa>=n/2){
				midd=max(min(a[mi[k][1]][1],a[mi[k][1]][2]),a[mi[k][1]][3]);
				if(midd==a[mi[k][1]][2]){
					ansb++;
					cnt[i-1]+=midd;
				}
				else{
					ansc++;
					cnt[i-1]+=midd;
				}
			}
			else if(mi[k][0]==a[mi[k][1]][2]&&ansb<n/2){
				ansb++;
				cnt[i-1]+=mi[k][0];
			}
			else if(mi[k][0]==a[mi[k][1]][2]&&ansa>=n/2){
				midd=max(min(a[mi[k][1]][1],a[mi[k][1]][2]),a[mi[k][1]][3]);
				if(midd==a[mi[k][1]][1]){
					ansa++;
					cnt[i-1]+=midd;
				}
				else{
					ansc++;
					cnt[i-1]+=midd;
				}
			}
            else if(mi[k][0]==a[mi[k][1]][3]&&ansc<n/2){
            	ansc++;
            	cnt[i-1]+=mi[k][0];
			}
			else if(mi[k][0]==a[mi[k][1]][3]&&ansa>=n/2){
				midd=max(min(a[mi[k][1]][3],a[mi[k][1]][2]),a[mi[k][1]][1]);
				if(midd==a[mi[k][1]][2]){
					ansb++;
					cnt[i-1]+=midd;
				}
				else{
					ansa++;
					cnt[i-1]+=midd;
				}
			}
		}
		ansa=ansb=ansc=ans=x=s=0;
		memset(a,0,sizeof(a));
		memset(ma,0,sizeof(ma));
		memset(mi,0,sizeof(mi));
	}
	for(int i=0;cnt[i];i++){
		cout<<cnt[i];
	}
	return 0;
}
