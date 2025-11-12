#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,y,z;
}a[100005];
int maxx(node m){
	return max(m.x,max(m.y,m.z));
}
int minn(node m){
	return min(m.x,min(m.y,m.z));
}
bool cmp(node p,node q){
	return max(maxx(p),maxx(q));
}
int xuma(node m){
	int da=max(m.x,max(m.y,m.z));
	int ma;
	if(da==m.x){
		ma=1;
	}else if(da==m.y){
		ma=2;
	}else if(da==m.z){
		ma=3;
	}
	return ma;
}
int xumi(node m){
	int xiao=min(m.x,min(m.y,m.z));
	int mi;
	if(xiao==m.x&&xuma(m)!=1){
		mi=1;
	}else if(xiao==m.y&&xuma(m)!=2){
		mi=2;
	}else if(xiao==m.z&&xuma(m)!=3){
		mi=3;
	}
	return mi;
}
int ertiao(node c,node l){
	if(maxx(c)<maxx(l)){
		swap(c,l);
	}
	if(maxx(c)==c.x&&maxx(l)==l.x){
		int u=c.x+c.y+c.z-maxx(c)-minn(c);
		int b=l.x+l.y+l.z-maxx(l)-minn(l);
		return  max(c.x+b,l.x+u);
	}else if(maxx(c)==c.y&&maxx(l)==l.y){
		int u=c.x+c.y+c.z-maxx(c)-minn(c);
		int b=l.x+l.y+l.z-maxx(l)-minn(l);
		return max(c.y+b,l.y+u);
	}else if(maxx(c)==c.z&&maxx(l)==l.z){
		int u=c.x+c.y+c.z-maxx(c)-minn(c);
		int b=l.x+l.y+l.z-maxx(l)-minn(l);
		return max(c.z+b,l.z+u);
	}else if(xuma(c)!=xuma(l)){
		return maxx(c)+maxx(l);
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		if(n==2){
			node c,l;
			cin >> c.x >> c.y >> c.z;
			cin >> l.x >> l.y >> l.z;
			if(maxx(c)<maxx(l)){
				swap(c,l);
			}
			if(maxx(c)==c.x&&maxx(l)==l.x){
				int u=c.x+c.y+c.z-maxx(c)-minn(c);
				int b=l.x+l.y+l.z-maxx(l)-minn(l);
				cout << max(c.x+b,l.x+u);
			}else if(maxx(c)==c.y&&maxx(l)==l.y){
				int u=c.x+c.y+c.z-maxx(c)-minn(c);
				int b=l.x+l.y+l.z-maxx(l)-minn(l);
				cout << max(c.y+b,l.y+u);
			}else if(maxx(c)==c.z&&maxx(l)==l.z){
				int u=c.x+c.y+c.z-maxx(c)-minn(c);
				int b=l.x+l.y+l.z-maxx(l)-minn(l);
				cout << max(c.z+b,l.z+u);
			}else if(xuma(c)!=xuma(l)){
				cout << maxx(c)+maxx(l);
			}
			cout << endl;
		}else{
			int nn=n/2;
			for(int i=1;i<=n;i++){
				cin >> a[i].x >> a[i].y >> a[i].z;
			}
			sort(a+1,a+n+1,cmp);
			int cnt=0;
			int a1=0,a2=0,a3=0;
			for(int i=1;i<=n;i++){
				if(maxx(a[i])==a[i].x){
					int m=a[i].x+a[i].y+a[i].z-maxx(a[i])-minn(a[i]);
					int mm=6-xuma(a[i])-xumi(a[i]);
					int ce;
					if(mm==2){
						ce=a2;
					}else if(mm==3){
						ce=a3;
					}
					if(a1<nn){
						a1++;
						cnt+=a[i].x;
					}else if(ce<nn){
						if(mm==2){
							a2++;
							cnt+=a[i].y;
						}else if(mm=3){
							a3++;
							cnt+=a[i].z;
						}
					}else if((a2+a3-ce)<nn){
						if(mm==2){
							a3++;
							cnt+=a[i].z;
						}else if(mm=3){
							a2++;
							cnt+=a[i].y;
						}
					}
				}else if(maxx(a[i])==a[i].y){
					int m=a[i].x+a[i].y+a[i].z-maxx(a[i])-minn(a[i]);
					int mm=6-xuma(a[i])-xumi(a[i]);
					int ce;
					if(mm==1){
						ce=a1;
					}else if(mm==3){
						ce=a3;
					}
					if(a2<nn){
						a2++;
						cnt+=a[i].y;
					}else if(ce<nn){
						if(mm==1){
							a1++;
							cnt+=a[i].x;
						}else if(mm=3){
							a3++;
							cnt+=a[i].z;
						}
					}else if((a2+a3-ce)<nn){
						if(mm==1){
							a3++;
							cnt+=a[i].z;
						}else if(mm=3){
							a1++;
							cnt+=a[i].x;
						}
					}
				}else if(maxx(a[i])==a[i].z){
					int m=a[i].x+a[i].y+a[i].z-maxx(a[i])-minn(a[i]);
					int mm=6-xuma(a[i])-xumi(a[i]);
					int ce;
					if(mm==2){
						ce=a2;
					}else if(mm==1){
						ce=a1;
					}
					if(a3<nn){
						a3++;
						cnt+=a[i].z;
					}else if(ce<nn){
						if(mm==2){
							a2++;
							cnt+=a[i].y;
						}else if(mm=1){
							a1++;
							cnt+=a[i].x;
						}
					}else if((a2+a3-ce)<nn){
						if(mm==2){
							a1++;
							cnt+=a[i].x;
						}else if(mm=1){
							a2++;
							cnt+=a[i].y;
						}
					}
				}
			}
			int ans=0;
			for(int i=1;i<n;i+=2){
				ans+=ertiao(a[i],a[i+1]);
			}
			cout << max(ans,cnt) << endl;
		}
	}
	return 0;
}
