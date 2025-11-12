#include <bits/stdc++.h>
using namespace std;

const long long q=1e6+5;
struct a{
	long long aa,bb,cc,maxxa,maxxb,sa,sb,minn;
}a[q];

long long t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		long long n,aaa=0,bbb=0,ccc=0,ans=0;
		cin>>n;
		for(int i=0;i<n;i++){ //初始化 
			cin>>a[i].aa;
			cin>>a[i].bb;
			cin>>a[i].cc;
			a[i].minn=min(a[i].aa,min(a[i].bb,a[i].cc));
			if(a[i].aa>a[i].bb&&a[i].aa>a[i].cc){
				a[i].maxxa=a[i].aa;
				a[i].sa=1;
			}
			if(a[i].bb>a[i].aa&&a[i].bb>a[i].cc){
				a[i].maxxa=a[i].bb;
				a[i].sa=2;
			}
			if(a[i].cc>a[i].aa&&a[i].cc>a[i].bb){
				a[i].maxxa=a[i].cc;
				a[i].sa=1;
			}
			if(a[i].maxxa=a[i].aa){
				if(a[i].bb<a[i].cc){
					a[i].maxxb=a[i].cc;
					a[i].sb=3;
				}else{
					a[i].maxxb=a[i].bb;
					a[i].sb=2;
				}
			}
			if(a[i].maxxa=a[i].bb){
				if(a[i].aa<a[i].cc){
					a[i].maxxb=a[i].cc;
					a[i].sb=3;
				}else{
					a[i].maxxb=a[i].aa;
					a[i].sb=1;
				}
			}if(a[i].maxxa=a[i].cc){
				if(a[i].bb<a[i].aa){
					a[i].maxxb=a[i].aa;
					a[i].sb=1;
				}else{
					a[i].maxxb=a[i].bb;
					a[i].sb=2;
				}
			}
		}
		for(int i=0;i<n;i++){ //排序 
			for(int j=0;j<i;j++){
				if(a[j].maxxa<a[j+1].maxxa){
					long long qwe=a[j].aa;
					a[j].aa=a[j+1].aa;
					a[j+1].aa=qwe;
					qwe=a[j].bb;
					a[j].bb=a[j+1].bb;
					a[j+1].bb=qwe;
					qwe=a[j].cc;
					a[j].cc=a[j+1].cc;
					a[j+1].cc=qwe;
					qwe=a[j].maxxa;
					a[j].maxxa=a[j+1].maxxa;
					a[j+1].maxxa=qwe;
					qwe=a[j].sa;
					a[j].sa=a[j+1].sa;
					a[j+1].sa=qwe;
					qwe=a[j].maxxb;
					a[j].maxxb=a[j+1].maxxb;
					a[j+1].maxxb=qwe;
					qwe=a[j].sb;
					a[j].sb=a[j+1].sb;
					a[j+1].sb=qwe;
				}
			}
		}
		for(int i=0;i<n;i++){ //程序 
			if(a[i].sa==1){
				if(aaa<n/2){
					ans+=a[i].maxxa;
					aaa++;
				}else{
					if(a[i].sa==2){
						if(bbb<n/2){
							ans+=a[i].maxxb;
							bbb++;
						}else{
							ans+=a[i].maxxb;
							ccc++;
						}
					}else{
						if(ccc<n/2){
							ans+=a[i].maxxb;
							ccc++;
						}else{
							ans+=a[i].maxxb;
							bbb++;
						}
					}
				}
			}else if(a[i].sa==2){
				if(bbb<n/2){
					ans+=a[i].maxxa;
					bbb++;
				}else{
					if(a[i].sa==1){
						if(aaa<n/2){
							ans+=a[i].maxxb;
							aaa++;
						}else{
							ans+=a[i].maxxb;
							ccc++;
						}
					}else{
						if(ccc<n/2){
							ans+=a[i].maxxb;
							ccc++;
						}else{
							ans+=a[i].maxxb;
							aaa++;
						}
					}
				}
			}else if(a[i].sa==3){
				if(ccc<n/2){
					ans+=a[i].maxxa;
					ccc++;
				}else{
					if(a[i].sa==1){
						if(aaa<n/2){
							ans+=a[i].maxxb;
							aaa++;
						}else{
							ans+=a[i].maxxb;
							bbb++;
						}
					}else{
						if(bbb<n/2){
							ans+=a[i].maxxb;
							bbb++;
						}else{
							ans+=a[i].maxxb;
							aaa++;
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 