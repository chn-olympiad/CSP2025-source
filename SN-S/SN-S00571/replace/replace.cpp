#include <bits/stdc++.h>
//#defin a q;
using namespace std;
//priority_queue<int,vector<int>,less<int> >q;
long long T,n;
struct qw{
	string x,y;
}a[1000000],b[1000000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<=m;i++){
		cin>>b[i].x>>b[i].y;
	}
	for(int i=1;i<=m;i++){
		long long op=0;
		for(int j=1;j<=n;j++){
			string x=b[i].x;
			if(b[i].x.size()<a[j].x.size()){
				continue;
			}
			for(int k=0;k<x.size();k++){
				int flag=1;
				for(int l=0;l<a[j].x.size();l++){
					if(x[k+l]!=a[j].x[l]){
						flag=0;
					}
				}
				if(flag==1){
					for(int l=0;l<a[j].y.size();l++){
						x[k+l]=a[j].y[l];
//						cout<<b[i].y<<"-=";
					}
//					cout<<endl;
					k=k+a[j].x.size()-1;
					break;
//					cout<<x<<" "<<endl;
				}
			}
//			cout<<x<<" "<<b[i].y<<endl;
			if(x==b[i].y){
				op++;
			}
		}
		cout<<op<<endl;
	}
	return 0;
}
