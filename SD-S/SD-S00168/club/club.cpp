#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,maxn,need[114514],mina[3]={20005,20005,20005},maxx=-1,maxy=-1,maxz=-1,sumx=0,sumy=0,sumz=0;
struct sat{
	int x,y,z,maxi,numi;
}a[114514];
bool cmpx(sat x,sat y){
	return x.x>y.x;
}
bool cmpy(sat x,sat y){
	return x.y>y.y;
}
bool cmpz(sat x,sat y){
	return x.z>y.z;
}
bool cmp(sat x,sat y){
	return x.x+x.y+x.z>y.x+y.y+y.z;
}
void solve(){
	maxn=0,maxx=-1,maxy=-1,maxz=-1,sumx=0,sumy=0,sumz=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		a[i].maxi=max(a[i].x,max(a[i].y,a[i].z));
		a[i].numi=i;
	}
	if(n==2){
		cout<<a[1].maxi+a[2].maxi<<endl;
		return;
	}
	sort(a+1,a+n+1,cmpx);
	for(int i=1;i<=n/2;i++){
		sumx+=a[i].x;
		need[a[i].numi]+=1;
	}
	sort(a+1,a+n+1,cmpy);
	int inuse=0;
	for(int i=1;i<=n/2+inuse;i++){
		sumy+=a[i].y;
		need[a[i].numi]+=11;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(need[a[i].numi]!=1||need[a[i].numi]!=11||need[a[i].numi]!=111){
			int bk=0;
			for(int j=i;j<=n;j++){
				if(need[a[j].numi]==0){
					if(need[a[i].numi]==12){
						if(a[i].x+a[j].y>a[i].y+a[j].x){
							need[a[j].numi]=11;
							need[a[i].numi]=1;
							sumy-=a[i].y;
							sumy+=a[j].y;
						}else{
							need[a[i].numi]=11;
							need[a[j].numi]=1;
							sumx-=a[i].x;
							sumx+=a[j].x;
						}
					}else if(need[a[i].numi]==112){
						if(a[i].x+a[j].z>a[i].z+a[j].x){
							need[a[j].numi]=111;
							need[a[i].numi]=1;
							sumz-=a[i].z;
							sumz+=a[j].z;
						}else{
							need[a[i].numi]=111;
							need[a[j].numi]=1;
							sumx-=a[i].x;
							sumx+=a[j].x;
						}
					}else if(need[a[i].numi]==122){
						if(a[i].y+a[j].z>a[i].z+a[j].y){
							need[a[j].numi]=111;
							need[a[i].numi]=11;
							sumz-=a[i].z;
							sumz+=a[j].z;
						}else{
							need[a[i].numi]=111;
							need[a[j].numi]=11;
							sumy-=a[i].y;
							sumy+=a[j].y;
						}
					}else{
						for(int k=j+1;k<=n;k++){
							if(need[a[k].numi]==0){
								if(a[i].x+a[j].y+a[k].z>a[i].x+a[j].z+a[k].y&&a[i].x+a[j].y+a[k].z>a[i].y+a[j].x+a[k].z&&a[i].x+a[j].y+a[k].z>a[i].y+a[j].z+a[k].x&&a[i].x+a[j].y+a[k].z>a[i].z+a[j].x+a[k].y&&a[i].x+a[i].y+a[i].z>a[i].z+a[i].y+a[i].x){
									need[a[i].numi]=1;
									need[a[j].numi]=11;
									need[a[k].numi]=111;
								}else if(a[i].x+a[j].z+a[k].y>a[i].x+a[j].y+a[k].z&&a[i].x+a[j].z+a[k].y>a[i].y+a[j].x+a[k].z&&a[i].x+a[j].z+a[k].y>a[i].y+a[j].z+a[k].x&&a[i].x+a[j].z+a[k].y>a[i].z+a[j].x+a[k].y&&a[i].x+a[i].z+a[i].y>a[i].z+a[i].y+a[i].x){
									need[a[i].numi]=1;
									need[a[j].numi]=111;
									need[a[k].numi]=11;
								}else if(a[i].y+a[j].x+a[k].z>a[i].x+a[j].y+a[k].z&&a[i].y+a[j].x+a[k].z>a[i].x+a[j].z+a[k].y&&a[i].y+a[j].x+a[k].z>a[i].y+a[j].z+a[k].x&&a[i].y+a[j].x+a[k].z>a[i].z+a[j].x+a[k].y&&a[i].y+a[i].x+a[i].z>a[i].z+a[i].y+a[i].x){
									need[a[i].numi]=11;
									need[a[j].numi]=1;
									need[a[k].numi]=111;
								}else if(a[i].y+a[j].z+a[k].x>a[i].x+a[j].y+a[k].z&&a[i].y+a[j].z+a[k].x>a[i].x+a[j].z+a[k].y&&a[i].y+a[j].z+a[k].x>a[i].y+a[j].x+a[k].z&&a[i].y+a[j].z+a[k].x>a[i].z+a[j].x+a[k].y&&a[i].y+a[i].z+a[i].x>a[i].z+a[i].y+a[i].x){
									need[a[i].numi]=11;
									need[a[j].numi]=111;
									need[a[k].numi]=1;
								}else if(a[i].z+a[j].x+a[k].y>a[i].x+a[j].y+a[k].z&&a[i].z+a[j].x+a[k].y>a[i].x+a[j].z+a[k].y&&a[i].z+a[j].x+a[k].y>a[i].y+a[j].x+a[k].z&&a[i].z+a[j].x+a[k].y>a[i].y+a[j].z+a[k].x&&a[i].z+a[i].x+a[i].y>a[i].z+a[i].y+a[i].x){
									need[a[i].numi]=111;
									need[a[j].numi]=1;
									need[a[k].numi]=11;
								}else{
									need[a[i].numi]=111;
									need[a[j].numi]=11;
									need[a[k].numi]=1;
								}
							}
						}
					}
				}
			}
		}
	}
	int sumn=0,n1=0,n2=0,n3=0;
	for(int i=1;i<=n;i++){
		if(need[a[i].numi]==1&&n1<n/2){
			n1++;
//			cout<<"1 "<<a[i].x<<endl;
			sumn+=a[i].x;
		}else if(need[a[i].numi]==11&&n2<n/2){
			n2++;
//			cout<<"2 "<<a[i].y<<endl;
			sumn+=a[i].y;
		}else if(n3<n/2){
			n3++;
//			cout<<"3 "<<a[i].z<<endl;
			sumn+=a[i].z;
		}else{
			sumn+=a[i].maxi;
		}
	}
	cout<<sumn<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
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
/*
LEX666
RP++
*/
