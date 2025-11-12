#include<bits/stdc++.h>
using namespace std;
//²»¹»Ì°ËûÂèµÄ
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
const int N=1e5+5;
vector<int> x;
vector<int> y;
vector<int> z;
int t,n,a[N][4],maxn,ans;
int minx,miny,minz,minX,minY,minZ;
void getminx(){
	for(int i=0;i<x.size();i++){
		if(a[x[i]][1]<minx){
			minX=x[i];
			minx=a[x[i]][1];
			return;
		}
	}
}
void getminy(){
	for(int i=0;i<y.size();i++){
		if(a[y[i]][2]<miny){
			minY=y[i];
			miny=a[y[i]][2];
			return;
		}
	}
}
void getminz(){
	for(int i=0;i<z.size();i++){
		if(a[z[i]][3]<minz){
			minZ=z[i];
			minz=a[z[i]][3];
			return;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		x.clear();
		y.clear();
		z.clear();
		minx=INT_MAX;
		miny=INT_MAX;
		minz=INT_MAX;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==maxn){
				if(x.size()>=n/2){
					if(minx<a[i][1]){
						//if(a[i][1]-max(a[i][2],a[i][3])>minx-max(a[minX][2],a[minX][3])+minx-a[i][1]){
							ans+=a[i][1];
							ans-=minx;
							x.push_back(i); 
							if(a[minX][2]>=a[minX][3]){
								y.push_back(minX);
								ans+=a[minX][2];
								getminy();
							}else{
								z.push_back(minX);
								ans+=a[minX][3];	
								getminz();						
							}
							getminx();
						//	cout<<i<<" ";
						//}
					}else{
						if(a[i][1]-max(a[i][2],a[i][3])+a[i][1]-minx<minx-max(a[minX][2],a[minX][3])){
							ans+=a[i][1];
							ans-=minx;
							x.push_back(i); 
							if(a[minX][2]>=a[minX][3]){
								y.push_back(minX);
								ans+=a[minX][2];
								getminy();
							}else{
								z.push_back(minX);
								ans+=a[minX][3];	
								getminz();						
							}
							getminx();
						//	cout<<i<<" ";
						}
					} 
				}else{
					x.push_back(i);
					ans+=a[i][1];
					getminx();
				//	cout<<i<<" ";
				}
			}else if(a[i][2]==maxn){
				if(y.size()>=n/2){
					if(miny<a[i][2]){
						//if(a[i][2]-max(a[i][1],a[i][3])>miny-max(a[minX][1],a[minX][3])+minx-a[i][2]){
							ans+=a[i][2];
							ans-=miny;
							y.push_back(i);
							if(a[minY][1]>=a[minY][3]){
								x.push_back(minY);
								ans+=a[minY][1];
								getminx();
							}else{
								z.push_back(minY);
								ans+=a[minY][3];
								getminz();							
							}
							getminy();
						//	cout<<i<<" ";
						//}
					}else{
						if(a[i][2]-max(a[i][1],a[i][3])+a[i][2]-miny<miny-max(a[minY][1],a[minY][3])){
							ans+=a[i][2];
							ans-=miny;
							y.push_back(i);
							if(a[minY][1]>=a[minY][3]){
								x.push_back(minY);
								ans+=a[minY][1];
								getminx();
							}else{
								z.push_back(minY);
								ans+=a[minY][3];
								getminz();							
							}
							getminy();
							cout<<i<<" ";
						}
					} 
				}else{
					y.push_back(i);
					ans+=a[i][2];
					getminy();
				//	cout<<i<<" ";
				}
			}else{
				if(z.size()>=n/2){
					if(minz<a[i][3]){
						//if(a[i][3]-max(a[i][1],a[i][2])>minz-max(a[minZ][2],a[minZ][1])+minz-a[i][3]){
							ans+=a[i][3];
							ans-=minz;
							z.push_back(i);
							if(a[minZ][1]>=a[minZ][2]){
								x.push_back(minZ);
								ans+=a[minZ][1];
								getminx();
							}else{
								y.push_back(minZ);
								ans+=a[minZ][2];
								getminy();							
							}				
							getminz();			
						//	cout<<i<<" ";
						//}
					}else{
						if(a[i][3]-max(a[i][1],a[i][3])+a[i][3]-minz<minz-max(a[minZ][2],a[minZ][1])){
							ans+=a[i][3];
							ans-=minz;
							z.push_back(i);
							if(a[minZ][1]>=a[minZ][2]){
								x.push_back(minZ);
								ans+=a[minZ][1];
								getminx();
							}else{
								y.push_back(minZ);
								ans+=a[minZ][2];
								getminy();							
							}	
							getminz();
						//	cout<<i<<" ";
						}
					} 
				}else{
					z.push_back(i);
					ans+=a[i][3];
					getminz();
				//	cout<<i<<" ";
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
/*
#include<bits/stdc++.h>
using namespace std;



3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0




const int N=1e5+5;
vector<int> x;
vector<int> y;
vector<int> z;
int t,n,a[N][4],maxn,ans,ans2;
int minx,miny,minz,minX,minY,minZ;
void getminx(){
	for(int i=0;i<x.size();i++){
		if(a[x[i]][1]<minx){
			minX=x[i];
			minx=a[x[i]][1];
			return;
		}
	}
}
void getminy(){
	for(int i=0;i<y.size();i++){
		if(a[y[i]][2]<miny){
			minY=y[i];
			miny=a[y[i]][2];
			return;
		}
	}
}
void getminz(){
	for(int i=0;i<z.size();i++){
		if(a[z[i]][3]<minz){
			minZ=z[i];
			minz=a[z[i]][3];
			return;
		}
	}
}
int xx[N],yy[N],zz[N]; 
bool b[N],c[N];
int main(){
//	freopen("club2.in","r",stdin);
//	freopen("club2.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		ans2=0;
		cin>>n;
		x.clear();
		y.clear();
		z.clear();
		minx=INT_MAX;
		miny=INT_MAX;
		minz=INT_MAX;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i]=0;
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			maxn=max(a[i][1],max(a[i][2],a[i][3]));
			if(a[i][1]==maxn){
				if(x.size()>=n/2){
					if(minx<a[i][1]){
						//if(a[i][1]-max(a[i][2],a[i][3])>minx-max(a[minX][2],a[minX][3])+minx-a[i][1]){
							ans2+=a[i][1];
							ans2-=minx;
							x.push_back(i); 
							if(a[minX][2]>=a[minX][3]){
								y.push_back(minX);
								ans2+=a[minX][2];
								getminy();
							}else{
								z.push_back(minX);
								ans2+=a[minX][3];	
								getminz();						
							}
							getminx();
						//	cout<<i<<" ";
						//}
					}else{
						if(a[i][1]-max(a[i][2],a[i][3])+a[i][1]-minx<minx-max(a[minX][2],a[minX][3])){
							ans2+=a[i][1];
							ans2-=minx;
							x.push_back(i); 
							if(a[minX][2]>=a[minX][3]){
								y.push_back(minX);
								ans2+=a[minX][2];
								getminy();
							}else{
								z.push_back(minX);
								ans2+=a[minX][3];	
								getminz();						
							}
							getminx();
						//	cout<<i<<" ";
						}
					} 
				}else{
					x.push_back(i);
					ans2+=a[i][1];
					getminx();
				//	cout<<i<<" ";
				}
			}else if(a[i][2]==maxn){
				if(y.size()>=n/2){
					if(miny<a[i][2]){
						//if(a[i][2]-max(a[i][1],a[i][3])>miny-max(a[minX][1],a[minX][3])+minx-a[i][2]){
							ans2+=a[i][2];
							ans2-=miny;
							y.push_back(i);
							if(a[minY][1]>=a[minY][3]){
								x.push_back(minY);
								ans2+=a[minY][1];
								getminx();
							}else{
								z.push_back(minY);
								ans2+=a[minY][3];
								getminz();							
							}
							getminy();
						//	cout<<i<<" ";
						//}
					}else{
						if(a[i][2]-max(a[i][1],a[i][3])+a[i][2]-miny<miny-max(a[minY][1],a[minY][3])){
							ans2+=a[i][2];
							ans2-=miny;
							y.push_back(i);
							if(a[minY][1]>=a[minY][3]){
								x.push_back(minY);
								ans2+=a[minY][1];
								getminx();
							}else{
								z.push_back(minY);
								ans2+=a[minY][3];
								getminz();							
							}
							getminy();
							cout<<i<<" ";
						}
					} 
				}else{
					y.push_back(i);
					ans2+=a[i][2];
					getminy();
				//	cout<<i<<" ";
				}
			}else{
				if(z.size()>=n/2){
					if(minz<a[i][3]){
						//if(a[i][3]-max(a[i][1],a[i][2])>minz-max(a[minZ][2],a[minZ][1])+minz-a[i][3]){
							ans2+=a[i][3];
							ans2-=minz;
							z.push_back(i);
							if(a[minZ][1]>=a[minZ][2]){
								x.push_back(minZ);
								ans2+=a[minZ][1];
								getminx();
							}else{
								y.push_back(minZ);
								ans2+=a[minZ][2];
								getminy();							
							}				
							getminz();			
						//	cout<<i<<" ";
						//}
					}else{
						if(a[i][3]-max(a[i][1],a[i][3])+a[i][3]-minz<minz-max(a[minZ][2],a[minZ][1])){
							ans2+=a[i][3];
							ans2-=minz;
							z.push_back(i);
							if(a[minZ][1]>=a[minZ][2]){
								x.push_back(minZ);
								ans2+=a[minZ][1];
								getminx();
							}else{
								y.push_back(minZ);
								ans2+=a[minZ][2];
								getminy();							
							}	
							getminz();
						//	cout<<i<<" ";
						}
					} 
				}else{
					z.push_back(i);
					ans2+=a[i][3];
					getminz();
				//	cout<<i<<" ";
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			b[i]=0;
			c[i]=0;
		}
		for(int i=1;i<=n;i++){
			xx[i]=a[i][1];
		}
		sort(xx+1,xx+n+1);
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=n;j>n/2;j--){
				if(a[i][1]>=xx[j]) flag=1;
			}
			if(!flag) continue;
			ans+=a[i][1];
			b[i]=1;
		//	cout<<a[i][1]<<" "; 
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			yy[i]=a[i][2];
		}
		sort(yy+1,yy+n+1);
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=n;j>n/2;j--){
				if(a[i][2]>=yy[j]) flag=1;
			}
			if(!flag) continue;
			if(cnt>n/2) break;
			if(b[i]==1){
				if(a[i][2]>a[i][1]){
					ans+=a[i][2]-a[i][1];
					c[i]=1; 
					cnt++;
				//	cout<<a[i][2]-a[i][1]<<" "; 
				}	
			}else{
				ans+=a[i][2];
				c[i]=1; 
				cnt++;
			//	cout<<a[i][2]<<" "; 
			} 
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			zz[i]=a[i][3];
		}
		sort(zz+1,zz+n+1);
		for(int i=1;i<=n;i++){
			bool flag=0;
			for(int j=n;j>n/2;j--){
				if(a[i][3]>=zz[j]) flag=1;
			}
			if(!flag) continue;
			if(cnt>n/2) break;
			if(b[i]==1||c[i]==1){
				if(a[i][3]>a[i][1]&&b[i]==1){
					ans+=a[i][3]-a[i][1];
					cnt++; 
				//	cout<<a[i][3]-a[i][1]<<" "; 
				}else if(a[i][3]>a[i][2]&&c[i]==1){
					ans+=a[i][3]-a[i][2];
					cnt++;
				//	cout<<a[i][3]-a[i][2]<<" ";  
				}
			}else{
				ans+=a[i][3];
				cnt++; 
			//	cout<<a[i][3]<<" "; 
			}
		}
		cout<<max(ans,ans2)<<endl;
	}
	return 0;
} 
*/
