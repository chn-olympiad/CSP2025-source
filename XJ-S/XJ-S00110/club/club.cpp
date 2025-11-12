#include<bits/stdc++.h>
using namespace std;
int t,n,a[10010][5],v[10010][5],sum=0,flag1,flag2,flag3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			int m=0;
			if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][1]) m=1;
			else if(max(a[i][1],max(a[i][2],a[i][3]))==a[i][2]) m=2;
			else m=3;
			v[i][m]=1;
			//cout<<i<<" "<<m;
		}
		int i=0;
		while(i!=4){
			i++;
			int s=0;
			for(int j=1;j<=n;j++){
				s+=v[j][i];
			}
			//cout<<i<<" "<<s<<endl;
			flag1=flag2=flag3=0;
			while(s>(n/2)){
				int minn=2e9,vis=0;
				for(int x=1;x<=n;x++){
					if(v[x][i]==1){
						int jl=0;
						if(i==1) jl=a[x][i]-max(a[x][2],a[x][3]);
						else if(i==2) jl=a[x][i]-max(a[x][1],a[x][3]);
						else jl=a[x][i]-max(a[x][1],a[x][2]);
						if(jl<minn){
							vis=x;
							minn=jl;
						}
					}
				}
				if(i==1){
					if(max(a[vis][2],a[vis][3])==a[vis][2]){
						v[vis][2]=1;
						v[vis][1]=0;
						flag2=1;
					}
					else{
						v[vis][3]=1;
						v[vis][1]=0;
						flag3=1;
					}
				}
				else if(i==2){
					if(max(a[vis][1],a[vis][3])==a[vis][1]){
						v[vis][1]=1;
						v[vis][2]=0;
						flag1=1;
					}
					else{
						v[vis][3]=1;
						v[vis][2]=0;
						flag3=1;
					}
				}
				if(i==3){
					if(max(a[vis][1],a[vis][2])==a[vis][1]){
						v[vis][1]=1;
						v[vis][3]=0;
						flag1=1;
					}
					else{
						v[vis][2]=1;
						v[vis][3]=0;
						flag2=1;
					}
				}
				//cout<<vis<<endl;
				s--;
			}
			if(flag1==1)i=0;
			if(flag2==1)i=1;
			if(flag3==1)i=2;
		}
		for(int i=1;i<=3;i++){
			for(int j=1;j<=n;j++){
				if(v[j][i]==1){
					sum+=a[j][i];
					//cout<<a[j][i]<<endl;
				}
				v[j][i]=0;
			} 
		} 
		cout<<sum<<endl;
	}
	return 0;
}
