#include<vector>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<iomanip>
#define int long long
using namespace std;
int n,m,a[33][33],b[331][331],f,kkk;
vector<int> l;
signed main(){
	ifstream in("seat.in");
	ofstream out("seat.out");
	in>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			in>>a[i][j];
			l.push_back(a[i][j]);
			if(i==1&&j==1) kkk=a[i][j];
		}
	}
	sort(l.begin(),l.end());
	reverse(l.begin(),l.end());
	for(int i=0;i<l.size();i++){
		if(l[i]==kkk){
			f=i+1;
			break;
		}
	}
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				f--;
				if(f==0){out<<i<<' '<<j;return 0;}
			}
		}else{
			for(int j=n;j>=1;j--){
				f--;
				if(f==0){out<<i<<' '<<j;return 0;}
			}
		}
	}
	return 0;
}
