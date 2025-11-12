#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x,y,z;
}aa[100010];
long long t;
int n,e,m,x,y,z,ff=0,r[100010],a[5],b,c,f[100010][5];
int read(){
	int t=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		t=t*10+int(ch)-'0';
		ch=getchar();
	}return t*f;
}
int check(){
	if(a[1]>m)return 1;
	if(a[2]>m)return 2;
	if(a[3]>m)return 3;
	return 0;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	e=read();//cin>>e;//cout<<e<<"qeqwerqwerq\n";
	for(int qqq=1;qqq<=e;qqq++){
		memset(f,-100,sizeof(f));
		
		a[1]=0,a[2]=0,a[3]=0;//ta=0,tb=0,tc=0;
		t=0;
		
		n=read();//cin>>n;//cout<<n<<"qeqwerqwerq\n";
		m=n/2;
		for(int i=1;i<=n;i++){
			aa[i].x=read();aa[i].y=read();aa[i].z=read();
			//cin>>aa[i].x>>aa[i].y>>aa[i].z;
			//cout<<aa[i].x<<" "<<aa[i].y<<" "<<aa[i].z<<" \n";
			x=max(aa[i].x,max(aa[i].y,aa[i].z));
			t+=x;
			if(x==aa[i].x){
				a[1]++;
				
				f[i][1]=min(aa[i].x-aa[i].y,aa[i].x-aa[i].z);//cout<<i<<":"<<f[i][1]<<"->1\n";
			}
			else if(x==aa[i].y){
				
				a[2]++;
				f[i][2]=min(aa[i].y-aa[i].x,aa[i].y-aa[i].z);//cout<<i<<":"<<f[i][2]<<"->2\n";
			}
			else {
				a[3]++;
				f[i][3]=min(aa[i].z-aa[i].y,aa[i].z-aa[i].x);//cout<<i<<":"<<f[i][3]<<"->3\n";
			}
			
		}//cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<m<<"\n";
		/*for(int i=1;i<=n;i++){
			if(f[i][3]>=0)cout<<i<<":"<<f[i][3]<<"->3\n";
			if(f[i][2]>-1)cout<<i<<":"<<f[i][2]<<"->2\n";
			if(f[i][1]>-1)cout<<i<<":"<<f[i][1]<<"->1\n";
		}*/
			int fl=check();
			if(fl==0){
				cout<<t<<"\n";
			}
			else{
				int u=0;
				for(int i=1;i<=n;i++){
					if(f[i][fl]>=0){
						u++;
						r[u]=f[i][fl];
					}
				}
				sort(r+1,r+u+1);
				for(int i=1;i<=u;i++){
					//cout<<r[i]<<"w\n";
				}
				for(int i=1;i<=a[fl]-m;i++)t-=r[i];
				cout<<t<<"\n";
			}
			
		//cout<<"------------\n";	
	}
	return 0;
}




