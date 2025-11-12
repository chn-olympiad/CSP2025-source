#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int n,m,k;
long long cun[N],cen[N];
bool flag;
long long sum_cost1,sum_cost2;
struct city{
	int u,v;
	long long c;
};
//vector<city> vec[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
//		vec[i].u=x,vec[i].v=y;
		cen[i]=z;
	}
	for(int i=1;i<=k;i++){
		int a;cin>>a;
		if(a==0){
			flag=true;
			for(int j=1;j<=n;j++){
				cin>>cun[j];
			}
			sort(cun+1,cun+n+1);
			break;
		}	
	}
	sort(cen+1,cen+n+1);
	for(int i=1;i<=n;i++){
		sum_cost1+=cen[i];
	}
	if(flag){
		for(int i=1;i<=n;i++){
			while(cun[i]<cen[i]){
				sum_cost2+=cun[i];
				i++;
			}
			if(i+1<=n)sum_cost2+=cen[i+1];
		}
	}
	cout<<min(sum_cost1,sum_cost2);
	return 0;
}
