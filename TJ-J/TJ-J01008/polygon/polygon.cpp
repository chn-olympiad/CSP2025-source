#include<bits/stdc++.h>
using namespace std;
int n,a[5005],b[5005];
vector< vector<int> > vec;
queue<int> q;
int cnt=0;
bool pj(int a[]){ //sizeof(a)/4 > 2
	int summ=0,maxn=0;
	for (int i=1;i<=sizeof(a)/4;i++){
		summ+=a[i];
		if (a[i]>maxn) maxn=a[i];
	}
	if (summ <= 2*maxn) return false;
	return true;
}
void bfs(int nu){
	q.pop();
	for (int i=nu+1;i<=n;i++){
		q.push(i);
		b[i]=i;
		if (sizeof(b)/4 > 2  &&  pj(b)){
			cnt++;
			q.pop();
			for (int j=1;j<=sizeof(b)/4;j++){
				b[j]=0;
				
			}
		} 
	}
	cout << cnt;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	
	bfs(1);
	return 0;
}

