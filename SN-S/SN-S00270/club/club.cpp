//强立琨 SN-S00270 交大附中浐灞右岸学校
#include<bits/stdc++.h>
using namespace std;
long long t,n,tmp1,tmp2;
struct node{
	long long a;
	long long b;
	long long c;
	int d;
	int e;
};
node x[100050];
long long ans;
bool cmp1(node q,node f){
	if(q.d==1 && f.d==1){
		if(q.e==2 && f.e==2){
			return q.a-q.b>f.a-f.b;
		}
		else if(q.e==2 && f.e==3){
			return q.a-q.b>f.a-f.c;
		}
		else if(q.e==3 && f.e==2){
			return q.a-q.c>f.a-f.b;
		}
		else{
			return q.a-q.c>f.a-f.c; 
		}
	}
	if(q.d==1 && f.d!=1){
		return true;
	}
	if(q.d!=1 && f.d==1){
		return false; 
	}
}
bool cmp2(node q,node f){
	if(q.d==2 && f.d==2){
		if(q.e==1 && f.e==1){
			return q.b-q.a>f.b-f.a;
		}
		else if(q.e==1 && f.e==3){
			return q.b-q.a>f.b-f.c;
		}
		else if(q.e==3 && f.e==1){
			return q.b-q.c>f.b-f.a;
		}
		else{
			return q.b-q.c>f.b-f.c; 
		}
	}
	if(q.d==2 && f.d!=2){
		return true;
	}
	if(q.d!=2 && f.d==2){
		return false; 
	}
}
bool cmp3(node q,node f){
	if(q.d==3 && f.d==3){
		if(q.e==2 && f.e==2){
			return q.c-q.b>f.c-f.b;
		}
		else if(q.e==1 && f.e==2){
			return q.c-q.a>f.c-f.b;
		}
		else if(q.e==2 && f.e==1){
			return q.c-q.b>f.c-f.a;
		}
		else{
			return q.c-q.a>f.c-f.a; 
		}
	}
	if(q.d==3 && f.d!=3){
		return true;
	}
	if(q.d!=3 && f.d==3){
		return false; 
	}
}
bool cmp4(node q,node f){
	return q.a>f.a;
}
bool cmp5(node q,node f){
	return q.a-q.b>f.a-f.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		ans=0;
		tmp1=0;
		tmp2=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b==0){
				tmp1++;
			}
			if(x[i].c==0){
				tmp2++;
			}
			if(x[i].a>x[i].b && x[i].a>x[i].c){
				x[i].d=1;
				if(x[i].b > x[i].c){
					x[i].e=2;
				}
				else{
					x[i].e=3;
				}
			}
			else if(x[i].b>x[i].a && x[i].b>x[i].c){
				x[i].d=2;
				if(x[i].a > x[i].c){
					x[i].e=1;
				}
				else{
					x[i].e=3;
				}
			}
			else if(x[i].c>x[i].a && x[i].c>x[i].b){
				x[i].d=3;
				if(x[i].a > x[i].b){
					x[i].e=1;
				}
				else{
					x[i].e=2;
				}
			}
			else if(x[i].a==x[i].b){
				if(x[i].a>x[i].c){
					x[i].d=1;
					x[i].e=2;
				}
				else if(x[i].a<x[i].c){
					x[i].d=3;
					x[i].e=1;
				}
			}
			else if(x[i].a==x[i].c){
				if(x[i].a>x[i].b){
					x[i].d=1;
					x[i].e=3;
				}
				else if(x[i].a<x[i].b){
					x[i].d=2;
					x[i].e=1;
				}
			}
			else if(x[i].b==x[i].c){
				if(x[i].b>x[i].a){
					x[i].d=2;
					x[i].e=3;
				}
				else if(x[i].b<x[i].a){
					x[i].d=1;
					x[i].e=2;
				}
			}
			else{
				x[i].d=1;
				x[i].e=2;
			}
		} 
		if(tmp1==n && tmp2==n){
			sort(x+1,x+n+1,cmp4);
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
		}
		else if(tmp2==n){
			sort(x+1,x+n+1,cmp5);
			for(int i=1;i<=n/2;i++){
				ans+=x[i].a;
			}
			for(int i=n/2+1;i<=n;i++){
				ans+=x[i].b;
			}
		}
		else{
			sort(x+1,x+n+1,cmp1);
			for(int i=1;x[i].d==1&&i<=n;i++){
				if(i>n/2){
					if(x[i].e==2){
						ans+=x[i].b;
					}
					else{
						ans+=x[i].c; 
					}
				}
				else{
					ans+=x[i].a;
				}
			}
			sort(x+1,x+n+1,cmp2);
			for(int i=1;x[i].d==2&&i<=n;i++){
				if(i>n/2){
					if(x[i].e==1){
						ans+=x[i].a;
					}
					else{
						ans+=x[i].c; 
					}
				}
				else{
					ans+=x[i].b;
				}
			}
			sort(x+1,x+n+1,cmp3);
			for(int i=1;x[i].d==3&&i<=n;i++){
				if(i>n/2){
					if(x[i].e==2){
						ans+=x[i].b;
					}
					else{
						ans+=x[i].a; 
					}
				}
				else{
					ans+=x[i].c;
				}
			}
		}
		cout<<ans<<endl;
	} 
	return 0;
} 
