#include<bits/stdc++.h>
using namespace std;
int n,la,lb,lc,q1,q2,ld,t;
long long s;
struct p{
	int x,y,z;
}a[110000],b[110000],c[110000],xx;
struct p2{
	int x,y;
}d[110000];
bool ca(p x,p y){
	return x.x-max(x.y,x.z)<y.x-max(y.y,y.z);
}
bool cb(p x,p y){
	return x.y-max(x.x,x.z)<y.y-max(y.x,y.z);
}
bool cc(p x,p y){
	return x.z-max(x.y,x.x)<y.z-max(y.y,y.x);
}
bool cd(p2 x,p2 y){
	return x.x-x.y<y.x-y.y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		la=lb=lc=ld=q1=q2=s=0;
		for(int i=1;i<=100000;i++){
			a[i].x=a[i].y=a[i].z=b[i].x=b[i].y=b[i].z=c[i].x=c[i].y=c[i].z=d[i].x=d[i].y=0;
		}
		cin>>n;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&xx.x,&xx.y,&xx.z);
			if(xx.x>=xx.y&&xx.x>=xx.z){
				a[++la]=xx;
				s+=xx.x;
			}
			else if(xx.y>=xx.x&&xx.y>=xx.z){
				b[++lb]=xx;
				s+=xx.y;
			}
			else{
				c[++lc]=xx;
				s+=xx.z;
			}
		}
		//cout<<"QWQ\n";
		if(la>n/2){
			//cout<<"A"<<endl;
			sort(a+1,a+la+1,ca);
			for(int i=1;i<=la;i++){
				d[i].x=a[i].x-a[i].y;
				d[i].y=a[i].x-a[i].z;
			}
			q1=n/2-lb,q2=n/2-lc;
			ld=la;
		}
		else if(lb>n/2){
			//cout<<"B"<<endl;
			sort(b+1,b+lb+1,cb);
			for(int i=1;i<=lb;i++){
				d[i].x=b[i].y-b[i].x;
				d[i].y=b[i].y-b[i].z;
			}
			q1=n/2-la,q2=n/2-lc;
			ld=lb;
		}
		else if(lc>n/2){
			sort(c+1,c+lc+1,cc);
			for(int i=1;i<=lc;i++){
				d[i].x=c[i].z-c[i].x;
				d[i].y=c[i].z-c[i].y;
			}
			q1=n/2-la,q2=n/2-lb;
			ld=lc;
		}
		//cout<<lb<<" "<<n/2<<" "<<(lb>n/2)<<endl;
		int q=ld-n/2,i=0;
		sort(d+1,d+ld+1,cd);
//		for(int i=1;i<=ld;i++){
//			cout<<d[i].x<<" "<<d[i].y<<endl;
//		}
		//cout<<"AWA\n";
		while(q>0){
			q--;
			i++;
			if(q1>0){
				q1--;
				s-=d[i].x;
			}
			else{
				s-=d[i].y;
			}
		}
		cout<<s<<endl;	
	}

	return 0;
}
