#include<bits/stdc++.h>

using namespace std;
const int N=1e5+10;
int t;
int n;
struct A{
	int d[5];
	int fst,sed,trd;
}a[N];
bool cmp(int a,int b){
	return a>b;
}
struct B{
	int idx,f;
	int cha;
	bool operator < (const B &rhs) const{
		return cha>rhs.cha;
	}
};
priority_queue <B> pq[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
    	cin >>n;
//    	for (int i=1;i<=n;i++){
//    		cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
//		}
		for (int i=1;i<=n;i++){
    		cin >> a[i].d[1] >> a[i].d[2] >> a[i].d[3];
    		if (a[i].d[1]>=a[i].d[2]&&a[i].d[2]>=a[i].d[3]){
    			a[i].fst=1,a[i].sed=2,a[i].trd=3;
			}
			else if (a[i].d[1]>=a[i].d[3]&&a[i].d[3]>=a[i].d[2]){
    			a[i].fst=1,a[i].sed=3,a[i].trd=2;
			}
			else if (a[i].d[2]>=a[i].d[1]&&a[i].d[1]>=a[i].d[3]){
    			a[i].fst=2,a[i].sed=1,a[i].trd=3;
			}
			else if (a[i].d[2]>=a[i].d[3]&&a[i].d[3]>=a[i].d[1]){
    			a[i].fst=2,a[i].sed=3,a[i].trd=1;
			}
			else if (a[i].d[3]>=a[i].d[2]&&a[i].d[2]>=a[i].d[1]){
    			a[i].fst=3,a[i].sed=2,a[i].trd=1;
			}
			else if (a[i].d[3]>=a[i].d[1]&&a[i].d[1]>=a[i].d[2]){
    			a[i].fst=3,a[i].sed=1,a[i].trd=2;
			}
		}
		for (int i=1;i<=n;i++){
			pq[a[i].fst].push((B){i,1,a[i].d[a[i].fst]-a[i].d[a[i].sed]});
			while(pq[1].size()>n/2||pq[2].size()>n/2||pq[3].size()>n/2){
				B temp;
				if (pq[1].size()>n/2){
					temp=pq[1].top();pq[1].pop();
				}
				else if (pq[2].size()>n/2){
					temp=pq[2].top();pq[2].pop();
				}
				else if (pq[3].size()>n/2){
					temp=pq[3].top();pq[3].pop();
				}
				temp.f++;
				//cout << temp.idx << ' ' << temp.f << endl;
				int idx=temp.idx;
				if (temp.f==2){
					pq[a[idx].sed].push((B){idx,2,a[idx].d[a[idx].sed]-a[idx].d[a[idx].trd]});
					//cout << a[idx].d[a[idx].sed]-a[idx].d[a[idx].trd] << endl;
				}
				else if(temp.f==3){
					pq[a[idx].trd].push((B){idx,3,-0x3f3f3f3f});
				}
			}
			
			
			
			
		}
		long long ans=0;
		//cout << "1" << endl;
		while(!pq[1].empty()){
			int idx=pq[1].top().idx;
			if (pq[1].top().f==1) ans+=a[idx].d[a[idx].fst];
			else if (pq[1].top().f==2) ans+=a[idx].d[a[idx].sed];
			else if (pq[1].top().f==3) ans+=a[idx].d[a[idx].trd];
			//cout << pq[1].top().idx << ' ' << pq[1].top().f << endl;
			pq[1].pop();
		}
		//cout << "2" << endl;
		while(!pq[2].empty()){
			int idx=pq[2].top().idx;
			if (pq[2].top().f==1) ans+=a[idx].d[a[idx].fst];
			else if (pq[2].top().f==2) ans+=a[idx].d[a[idx].sed];
			else if (pq[2].top().f==3) ans+=a[idx].d[a[idx].trd];
			//cout << pq[2].top().idx << ' ' << pq[2].top().f << endl;
			pq[2].pop();
		}
		//cout << "3" << endl;
		while(!pq[3].empty()){
			int idx=pq[3].top().idx;
			if (pq[3].top().f==1) ans+=a[idx].d[a[idx].fst];
			else if (pq[3].top().f==2) ans+=a[idx].d[a[idx].sed];
			else if (pq[3].top().f==3) ans+=a[idx].d[a[idx].trd];
			//cout << pq[3].top().idx << ' ' << pq[3].top().f << endl;
			pq[3].pop();
		}
		cout << ans << '\n';

	}

	return 0;
}

