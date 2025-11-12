#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n[10000],a[10000][3],c[10000][3],s[3],f=0,b[10000],d[2];
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			cin>>a[n[i]][1]>>a[n[i]][2]>>a[n[i]][3];
		}
	} 
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n[i];j++){
			c[j][1]=max(a[j][1],a[j][2]);
			c[j][1]=max(c[j][1],a[j][3]);
			if(c[j][1]==a[j][3]){
				s[1]++;
				c[j][2]=max(a[j][3],a[j][2]);
				if(c[j][2]==a[j][2]){
					b[j]=2;
				}else{
					b[j]=3;
				}	
			}else if(c[j][1]==a[j][2]){
				s[2]++;
				c[j][2]=max(a[j][3],a[j][1]);
				if(c[j][2]==a[j][3]){
					b[j]=3;
				}else{
					b[j]=1;
				}	
			}else{
				s[3]++;
				c[j][2]=max(a[j][1],a[j][2]);
				if(c[j][2]==a[j][1]){
					b[j]=1;
				}else{
					b[j]=2;
				}	
			}
		
		}
		for(int j=1;j<=n[i];j++){
			f+=c[j][1];
		}
		while(s[1]>n[i]/2||s[2]>n[i]/2||s[3]>n[i]/2){
			d[1]=10000;
			for(int j=1;j<=n[i];j++){
				d[1]=min(d[1],c[j][1]-c[j][2]);
				if(d[1]==c[j][1]){
					d[2]=j;
				}
			}
			if(s[1]>n[i]/2){
				s[1]-=1;
				s[b[d[2]]]+=1;
			}else if(s[2]>n[i]/2){
				s[2]-=1;
				s[b[d[2]]]+=1;
			}else{
				s[3]-=1;
				s[b[d[2]]]+=1;
			}
			f-=d[1];
		}
		
		cout<<f<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
