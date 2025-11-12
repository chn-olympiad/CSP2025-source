#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+7;
int n,q;
string xxx[maxn][2];
string x,y;

ll check(int u){
	string op=xxx[u][0],po=xxx[u][1];
	if(op==x&&po==y)return 1ll;
	int s=op.size();
	if(s>x.size())return 0;
	ll sum=0;
	for(int i=1;i<=x.size()-s+1;i++){
		string xx=x;
		bool pt=0;
		for(int j=0;j<s;j++){
			if(xx[i+j-1]!=op[j])pt=1;
		}
		if(pt==0){
//			cout<<"#";
			for(int j=0;j<s;j++){
				xx[i+j-1]=po[j];
			}
		}
		if(xx==y)sum++;
	}
	return sum;
}

//struct ty{
//	char a,b;
//	int b_lo;//b
//};
//ty orrr[maxn][2];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>q;
//	if(n<=100&&q<=100){
		for(int i=1;i<=n;i++){
			cin >> xxx[i][0] >> xxx[i][1];
		}
		while(q--){
			cin>>x>>y;
			ll ans=0;
			for(int i=1;i<=n;i++){
				ans+=check(i);
			}
			cout<<ans<<"\n";
		}	
//	}
//	else{
//		for(int i=1;i<=n;i++){
//			cin>>xxx[i][0]>>xxx[i][1];
//		}
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<=1;j++){
//				string opq=xxx[i][j];
//				if(opq[0]==opq[1]){
//					orrr[i][j].a=opq[0];
//					for(int gh=2;gh<opq.size();gh++){
//						if(opq[gh]!=opq[0]){
//							orrr[i][j].b=opq[gh];
//							orrr[i][j].b_lo=gh;
//							break;
//						}
//					}
//				}
//				else{
//					if(opq[0]==opq[2])
//				}
//			}
//		}
//	}
	return 0;
}

