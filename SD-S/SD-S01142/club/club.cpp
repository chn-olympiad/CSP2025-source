#include<bits/stdc++.h>
#define int long long
using namespace std;
struct ren{
	int a,b,c,d,e;
	int max()const{
		return d-e;
	}
	void in(){
		cin>>a>>b>>c;
		d=::max({a,b,c});
		if(a>=b&&a>=c){
			e=::max(b,c);
		}
		if(b>=a&&b>=c){
			e=::max(a,c);
		}
		if(c>=b&&c>=a){
			e=::max(a,b);
		}
	}
	bool operator<(const ren&o){
		return max()>o.max(); 
	}
};
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<ren> f(n);
		for(int i=0;i<n;i++){
			f[i].in();
		}
		if(n<=20){
			int ans=0;
			int m=pow(3,n);
			//cout<<m;
			for(int i=0;i<m;i++){
				int an=0,a=0,b=0,c=0;
				int k=i;
				for(int j=0;j<n;j++){	
					if(k%3==0){
						if(a==n/2)break;
						a++;
						an+=f[j].a;
					}else if(k%3==1){
						if(b==n/2)break;
						b++;
						an+=f[j].b;
					}else{
						if(c==n/2)break;
						c++;
						an+=f[j].c;	
					}
					k/=3;
				}
				ans=max(ans,an);
			}
			cout<<ans<<endl;
			continue;
		}
		sort(f.begin(),f.end());
		int a=0,b=0,c=0,an=0;
		for(ren i:f){
			int m=i.d;
			if(m==i.a){
				if(a<n/2){
					an+=m;
					a++;
					continue;
				}
				if(i.b>i.c){
					an+=i.b;
					b++;
				}else{
					an+=i.c;
					c++;
				}
			}
			if(m==i.b){
				if(b<n/2){
					an+=m;
					b++;
					continue;
				}
				if(i.a>i.c){
					an+=i.a;
					a++;
				}else{
					an+=i.c;
					c++;
				}
			}
			if(m==i.c){
				if(c<n/2){
					an+=m;
					c++;
					continue;
				}
				if(i.a>i.b){
					an+=i.a;
					a++;
				}else{
					an+=i.b;
					b++;
				}
			}
		}
		cout<<an<<endl;
	}
	return 0;
}

