#include<bits/stdc++.h>
using namespace std;
int t,n,a1[10010],a2[10010],a3[10010],flag[5];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a1[j]>>a2[j]>>a3[j];
		}
		for(int z=1;z<=3;z++){
			flag[z]=0;
		}
		
		int sum=0;
		for(int j=1;j<=n;j++){
			int a=a1[j],b=a2[j],c=a3[j];
			if(a=max(max(a,b),c)&&flag[1]<(n/2)){
				sum+=a;
				flag[1]++;
				continue;
			}else if(a=max(max(a,b),c)&&!flag[1]<(n/2)){
				if(b=max(b,c)&&flag[2]<(n/2)){
					sum+=b;
					flag[2]++;
					continue;
				}else if(b=max(b,c)&&!flag[2]<(n/2)){
					sum+=c;
					flag[3]++;
					continue;
				}
				if(c=max(b,c)&&flag[3]<(n/2)){
					sum+=c;
					flag[3]++;
					continue;
				}else if(c=max(b,c)&&!flag[3]<(n/2)){
					sum+=b;
					flag[2]++;
					continue;
				}
			}
			
			if(b=max(max(a,b),c)&&flag[2]<(n/2)){
				sum+b;
				flag[2]++;
				continue;
			}else if(b=max(max(a,b),c)&&!flag[2]<(n/2)){
				if(a=max(a,c)&&flag[1]<(n/2)){
					sum+=a;
					flag[1]++;
					continue;
				}else if(a=max(a,c)&&!flag[1]<(n/2)){
					sum+=a;
					flag[1]++;
					continue;
				}
				if(c=max(a,c)&&flag[3]<(n/2)){
					sum+=c;
					flag[3]++;
					continue;
				}else if(c=max(a,c)&&!flag[3]<(n/2)){
					sum+=a;
					flag[1]++;
					continue;
				}
			}
			
			if(c=max(max(a,b),c)&&flag[3]<(n/2)){
				sum+=c;
				flag[3]++;
				continue;
			}else if(c=max(max(a,b),c)&&!flag[3]<(n/2)){
				if(a=max(b,a)&&flag[1]<(n/2)){
					sum+=a;
					flag[1]++;
					continue;
				}else if(a=max(b,a)&&!flag[1]<(n/2)){
					sum+=b;
					flag[2]++;
					continue;
				}
				if(b=max(a,b)&&flag[2]<(n/2)){
					sum+=b;
					flag[2]++;
					continue;
				}else if(b=max(a,b)&&!flag[2]<(n/2)){
					sum+=a;
					flag[1]++;
					continue;
				}
			}
		}
		cout<<sum<<endl;
	}

	

	fclose(stdin);
	fclose(stdout);

	return 0;
	
} 

