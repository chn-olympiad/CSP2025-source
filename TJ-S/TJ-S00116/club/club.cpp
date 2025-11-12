#include <iostream>
#include <vector>
using namespace std;
struct per{
	int a[3];
}a[100010];
int f1,f2,f3,n;
long long ans,sna;bool flag;
void dfs(int i){
	if(i==n){
		sna=(sna>ans?sna:ans);
		flag=1;
		return;
	}
	if(f1<n/2){
	f1++;ans+=a[i].a[0];
	dfs(i+1);
	ans-=a[i].a[0];f1--;
	}if(f2<n/2){
	ans+=a[i].a[1];f2++;
	dfs(i+1);
	ans-=a[i].a[1];f2--;
	}if(f3<n/2){
	ans+=a[i].a[2];f3++;
	dfs(i+1);
	ans-=a[i].a[2];f3--;
	} 
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		sna=0;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i].a[0] >> a[i].a[1] >> a[i].a[2];
		}
		dfs(0);
		cout << sna << endl;
	}
}
