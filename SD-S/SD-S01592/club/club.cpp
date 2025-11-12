#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T;
int fa=0;
long long n;
long long sum=0;
long long d=0;
bool cmp(long a,long b){
	return a>b;
}
struct p1{
	long long m1;
	long long a;
}f[N];
struct p2{
	long long m2;
	long long b;
}s[N];
struct p3{
	long long m3;
	long long c;
}t[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	f[1].a=0;
	s[1].b=0;
	t[1].c=0;
	while(T--){
		for(int i=1;i<=n;i++){
			f[i].m1=0;
			f[i].a=0;
			s[i].m2=0;
			s[i].b=0;
			t[i].m3=0;
			t[i].c=0;
		}	
		sum=0;
		cin>>n;
		long long w=n/2;
		for(int i=1;i<=n;i++){
			f[i].m1=i;
			s[i].m2=i;
			t[i].m3=i;
		}
		for(int i=1;i<=n;i++){
			cin>>f[i].a>>s[i].b>>t[i].c;
			if(s[i].b!=0 || t[i].c!=0) fa=1;
		}
		for(int i=1;i<=n;i++){
			for(int y=i+1;y<=n;y++){
				if(f[i].a<f[y].a){
					swap(f[i].a,f[y].a);
					swap(f[i].m1,f[y].m1);
				}				
			}
		}
		if(fa==0){
			for(int j=1;j<=w;j++) sum+=f[j].a;
			cout<<sum;
			continue;
		}	
		for(int i=1;i<=n;i++){
			for(int y=i+1;y<=n;y++){
				if(f[i].a<f[y].a){
					swap(f[i].a,f[y].a);
					swap(f[i].m1,f[y].m1);
				}
				if(s[i].b<s[y].b){
					swap(s[i].b,s[y].b);
					swap(s[i].m2,s[y].m2);
				}
				if(t[i].c<t[y].c){
					swap(t[i].c,t[y].c);
					swap(t[i].m3,t[y].m3);
				}
			}//ÅÅÐòÍê±Ï
		}

		for(int i=1;i<=n;i++){
			d=max(max(f[i].a,s[i].b),t[i].c);
			sum+=d;
			if(d==f[i].a){
				int q=f[i].m1;
				for(int j=1;j<=n;j++){
					if(s[j].m2==q){
						s[j].b==0;
					}else if(t[j].m3==q){
						t[j].c==0;
					}
				}
			}
			if(d==s[i].b){
				int q=s[i].m2;
				for(int j=1;j<=n;j++){
					if(f[j].m1==q){
						f[j].a==0;
					}else if(t[j].m3==q){
						t[j].c==0;
					}
				}
			}
			if(d==t[i].c){
				int q=t[i].m3;
				for(int j=1;j<=n;j++){
					if(s[j].m2==q){
						s[j].b==0;
					}else if(f[j].m1==q){
						f[j].a==0;
					}
				}					
			}
			for(int y=i+1;y<=n;y++){
				if(f[i].a<f[y].a){
					swap(f[i].a,f[y].a);
					swap(f[i].m1,f[y].m1);
				}
				for(int x=n;x>1;x--){
					f[x].a=f[x-1].a;
				}
				f[1].a=0; 
				if(s[i].b<s[y].b){
					swap(s[i].b,s[y].b);
					swap(s[i].m2,s[y].m2);
				}
				for(int x=n;x>1;x--){
					s[x].b=s[x-1].b;
				}
				s[1].b=0; 
				if(t[i].c<t[y].c){
					swap(t[i].c,t[y].c);
					swap(t[i].m3,t[y].m3);
				}	
				for(int x=n;x>1;x--){
					t[x].c=t[x-1].c;
				}
				t[1].c=0; 									
			}			
		}
		cout<<sum<<endl;
	}
	return 0;
}
