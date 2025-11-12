#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
priority_queue<pii,vector<pii>,greater<pii> > a1,b1,c1;//大顶堆 
//priority_queue<pii,vector<pii>,greater<pii> > p;//小顶堆 
//first  满意度
//second  成员编号 
ll n;
struct wwww{
	int a,b,c;
}club[100010];
bool qu[100010];
ll timee[4]={0,0,0,0},maxx,ans=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		timee[1]=0;
		timee[2]=0;
		timee[3]=0;
		ans=0;
		int n;
		cin>>n;
		if(n==2){
			int aa,bb,cc,x,y,z,mm,nn;
			cin>>aa>>bb>>cc>>x>>y>>z;
			if(aa>bb&&aa>cc){
				nn=1;
				ans=aa;
			}else if(bb>cc){
				nn=2;ans=bb;
			}else {
				nn=3;ans=cc;
			}
			if(x>y&&x>z){
				mm=1;ans+=x;
			}else if(y>z){
				mm=2;ans+=y;
			}else {
				mm=3;ans+=z;
			}
			if(nn==mm){
				if(nn==1){
					ans-=min(aa-max(bb,cc),x-max(y,z));
				}else if(nn==2){
					ans-=min(bb-max(aa,cc),y-max(x,z));
				}else{
					ans-=min(cc-max(bb,aa),z-max(y,x));
				}
				cout<<ans<<endl;
			}else{
				cout<<ans<<endl;
			}
			continue;
		}
		maxx=n/2;
		for(int i=1;i<=n;i++){
			cin>>club[i].a>>club[i].b>>club[i].c;
			int minn=min(club[i].a,min(club[i].b,club[i].c));
			int x=club[i].a-minn,y=club[i].b-minn,z=club[i].c-minn;
			club[i].a-=minn;
			club[i].b-=minn;
			club[i].c-=minn;
			ans+=minn;
			pii noww;
			if(x>=y&&x>=z){//个人最想去哪就去哪 
				noww.first=x;
				noww.second=i;
				a1.push(noww);
				timee[1]++;
			}else if(y>=z){
				noww.first=y;
				noww.second=i;
				b1.push(noww);
				timee[2]++;
			}else{
				noww.first=z;
				noww.second=i;
				c1.push(noww);
				timee[3]++;
			}
		}
//		cout<<a1.size()<<" "<<b1.size()<<" "<<c1.size()<<endl;
		while(timee[1]>maxx){int x=club[a1.top().second].a,y=club[a1.top().second].b,z=club[a1.top().second].c;
			if(y>z){
				b1.push({y,a1.top().second});
				timee[2]++;
			}else if(y==z){
				if(timee[2]>timee[3]){
					c1.push({z,a1.top().second});
					timee[3]++;
				}else{
					b1.push({y,a1.top().second});
//					cout<<1;
					timee[2]++;
				}
			}else{
				c1.push({z,a1.top().second});
				timee[3]++;
			}
			a1.pop();
			timee[1]--;
		}
//		cout<<a1.size()<<" "<<b1.size()<<" "<<c1.size()<<endl;
//		while(!a1.empty()){cout<<a1.top().first<<" ";
//			a1.pop();
//			
//		}
//		cout<<endl;
//		while(!b1.empty()){cout<<b1.top().first<<" ";
//			b1.pop();
//			
//		}
//		cout<<endl;
//		while(!c1.empty()){cout<<c1.top().first<<" ";
//			c1.pop();
//			
//		}
//		cout<<endl;
		while(timee[2]>maxx){int x=club[b1.top().second].a,y=club[b1.top().second].b,z=club[b1.top().second].c;
			if(x>z){
				a1.push({x,b1.top().second});
				timee[1]++;
			}else if(x==z){
				if(timee[1]>timee[3]){
					c1.push({z,b1.top().second});
					timee[3]++;
				}else{
					a1.push({x,b1.top().second});
//					cout<<1;
					timee[1]++;
				}
			}else{
				c1.push({z,b1.top().second});
				timee[3]++;
			}
			b1.pop();
			timee[2]--;
		}
//		cout<<a1.size()<<" "<<b1.size()<<" "<<c1.size()<<endl;
//		while(!a1.empty()){cout<<a1.top().first<<" ";
//			a1.pop();
//			
//		}
//		cout<<endl;
//		while(!b1.empty()){cout<<b1.top().first<<" ";
//			b1.pop();
//			
//		}
//		cout<<endl;
//		while(!c1.empty()){cout<<c1.top().first<<" ";
//			c1.pop();
//			
//		}
//		cout<<endl;
		while(timee[3]>maxx){int x=club[c1.top().second].a,y=club[c1.top().second].b,z=club[c1.top().second].c;
			if(x>y){
				a1.push({x,c1.top().second});
				timee[1]++;
			}else if(x==y){
				if(timee[1]>timee[2]){
					b1.push({y,c1.top().second});
					timee[2]++;
				}else{
					a1.push({x,c1.top().second});
//					cout<<1;
					timee[1]++;
				}
			}else{
				b1.push({y,c1.top().second});
				timee[2]++;
			}
			c1.pop();
			timee[3]--;
		}
//		cout<<a1.size()<<" "<<b1.size()<<" "<<c1.size()<<endl;
		while(!a1.empty()){ans+=a1.top().first;
			a1.pop();
			
		}
		while(!b1.empty()){ans+=b1.top().first;
			b1.pop();
			
		}
		while(!c1.empty()){ans+=c1.top().first;
			c1.pop();
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

