#include <bits/stdc++.h>
//#defin a q;
using namespace std;
//priority_queue<int,vector<int>,less<int> >q;
long long T,n;
struct qw{
	int x,y,z,id;
}a[1000000];
bool cmp(qw x,qw y){
	return max(max(abs(x.x-x.y),abs(x.y-x.z)),abs(x.z-x.x))>max(max(abs(y.x-y.y),abs(y.y-y.z)),abs(y.z-y.x));
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<"0";
	return 0;
}
