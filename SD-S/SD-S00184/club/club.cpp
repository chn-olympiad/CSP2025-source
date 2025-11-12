#include<bits/stdc++.h>
#define int long long

using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
}x[N];
bool cmp(node A,node B){
	return A.a>B.a;
}
bool cmp1(node A,node B){
//	return abs(A.a-B.a)>abs(B.a-A.a);
	return A.a>B.a;
	
}
bool cmp2(node A,node B){
	return A.b>B.b;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		bool f1=0,f2=0;
		for(int i=1;i<=n;i++){
			cin>>x[i].a>>x[i].b>>x[i].c;
			if(x[i].b!=0) f1=1;
			if(x[i].c!=0) f2=1;
		}
		if(f1==0&&f2==0){
			sort(x+1,x+1+n,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++){
				sum+=x[i].a;
			}
			cout<<sum<<endl;
		}
		else if(f2==0){
		int cnta=0,cntb=0;
		int wa,wb;
		deque<int>q;
		deque<int>qq;
		int suma=0,sumb=0;
		for(int i=1;i<=n;i++){
			if(x[i].a>x[i].b){
				if(cnta<n/2){
					cnta++;
//					if(x[i].a<q.front()){
//						q.push_front(x[i].a);
//						q q.push_front(i); 
//					}
					int cnt=0;
					int p[N]={0},pp[N]={0};
					while(x[i].a>q.front()){
							p[++cnt]=q.front();
							pp[cnt]=qq.front();
							qq.pop_front();
							q.pop_front();
						}
						q.push_front(x[i].a);
						qq.push_front(i);
						while(cnt){
							q.push_front(p[cnt]);
							qq.push_front(pp[cnt--]);
//							cnt--;
						}
					suma+=x[i].a;
				}
				else{
					if(x[i].a>q.front()&&suma-q.front()+x[i].a+sumb+x[qq.front()].b>suma+sumb){
						suma-=q.front();
						suma+=x[i].a;
						int r=qq.front();
						sumb+=x[r].b;
						cntb++;
						int cnt=0;
						int p[N]={0},pp[N]={0};
						while(x[i].a>q.front()){
							p[++cnt]=q.front();
							pp[cnt]=qq.front();
							qq.pop_front();
							q.pop_front();
						}
						q.push_front(x[i].a);
						qq.push_front(i);
						while(cnt){
							q.push_front(p[cnt]);
							qq.push_front(pp[cnt--]);
//							cnt--;
						}
						q.pop_front();
						qq.pop_front();
					}
					else{
						sumb+=x[i].b;
						cntb++;
					}
				}
			}
			else{
				sumb+=x[i].b;
				cntb++;
			}
		}
		int anss=suma+sumb;
		cout<<anss<<endl;
	}
	}
	return 0;
} 
