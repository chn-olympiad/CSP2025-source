#include<iostream>
#include<algorithm>
using namespace std;
struct s{
	int p[4];
};
s b[114514];
s c[4][114514];
int t,n,d[4],m,f,ans;
bool cmp(s a,s b){
	if(f==1){
		return a.p[1]-max(a.p[2],a.p[3])>b.p[1]-max(b.p[2],b.p[3]);
	}else if(f==2){
		return a.p[2]-max(a.p[1],a.p[3])>b.p[2]-max(b.p[1],b.p[3]);
	}else if(f==3){
		return a.p[3]-max(a.p[1],a.p[2])>b.p[3]-max(b.p[1],b.p[2]);
	}else cout<<"You SB!!!!!"<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=d[1]=d[2]=d[3]=0;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>b[i].p[1]>>b[i].p[2]>>b[i].p[3];
			m=max(b[i].p[1],max(b[i].p[2],b[i].p[3]));
			for(int j=1;j<=3;j++){
				if(b[i].p[j]==m){
					c[j][d[j]++]=b[i];
					ans+=b[i].p[j];
					break;
				}
			}
		}
//		cout<<d[1]<<" "<<d[2]<<" "<<d[3]<<" ";
		if(max(d[1],max(d[2],d[3]))<=n/2){
//			cout<<"*";
			cout<<ans<<endl;
			continue;
		}else{
			for(int i=1;i<=3;i++){
				if(d[i]>n/2){
					f=i;
//					cout<<f<<" ";
				}
			}
		}
//		cout<<d[f]<<endl;
		int o=d[f];
		sort(c[f],c[f]+o,cmp);
//		for(int i=0;i<n;i++)cout<<c[f][i].p[1]<<" "<<c[f][i].p[2]<<" "<<c[f][i].p[3]<<endl;
		for(int i=d[f]-1;i>=n/2;i--){
//			cout<<ans<<" ";
			if(f==1){
				ans-=c[f][i].p[1]-max(c[f][i].p[2],c[f][i].p[3]);
			}else if(f==2){
				ans-=c[f][i].p[2]-max(c[f][i].p[1],c[f][i].p[3]);
			}else if(f==3){
				ans-=c[f][i].p[3]-max(c[f][i].p[1],c[f][i].p[2]);
			}else cout<<"You SB!!"<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
