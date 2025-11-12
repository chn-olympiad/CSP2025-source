#include<bits/stdc++.h>

using namespace std;
long long n,m,a[200],b[15][15],d,e;//b是地图 不要再用C了用过了
bool cmp(long long a,long long b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	d=a[1];
	sort(a+1,a+n*m+1,cmp);
	if(a[1]==d){
		cout<<"1 1";
		return 0;
	}else if(a[n*m]==d){
		cout<<n<<" "<<m;
		return 0;
	}//两种特殊头尾情况 
	e=1;
	int f=1,c=1;//f是列 
	while(f<=n&&c<=m){
		if(f%2==0){
			for(int i=m;i>=1;i--){
				b[f][i]=a[e];
				if(a[e]==d){
					cout<<f<<" "<<i;
					return 0;
				}
				e++;
			}
		}
		if(f%2!=0){
			for(int i=1;i<=m;i++){
				b[f][i]=a[e];
				if(a[e]==d){
					cout<<f<<" "<<i;
					return 0;
				}
				e++;
			}
		}
		f++,c++;
	}
	return 0;
}
