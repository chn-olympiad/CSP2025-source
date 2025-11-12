#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=110;
int n,m;
int a[N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1];
	sort(a+1,a+n*m+1);
	reverse(a+1,a+n*m+1);
	int p=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			p=i;
			break;
		}
	}
	int cnt=1;
	int px=1,py=1;
	int op=1;
	while(cnt<p){
		if(op==1){
			cnt++;
			py++;
			if(py==n+1){
				op=0;
				py=n;
				px++;
			}
		}else{
			cnt++;
			py--;
			if(py==0){
				op=1;
				py=1;
				px++;
			}
		}
	}
	cout<<px<<' '<<py<<'\n';
	return 0;
}