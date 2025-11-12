#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct node{
	int num,id;
};
node a[maxn],b[maxn],c[maxn];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen ("club.in","r",stdin);
	freopen ("club.out","w",stdout);
	int t;
	cin >> t;
	while (t--){
		int n;
		cin >> n;
		for (int i=1;i<=n;i++){
			cin >> a[i].num >> b[i].num >> c[i].num;
			a[i].id=b[i].id=c[i].id=i;
		}
		if (n==2){
			int num1,num2,num3,num4,num5,num6;
			num1=a[1].num+b[2].num;
			num2=a[1].num+c[2].num;
			num3=b[1].num+a[2].num;
			num4=b[1].num+c[2].num;
			num5=c[1].num+a[2].num;
			num6=c[1].num+b[2].num;
			cout <<max(num1,max(num2,max(num3,max(num4,max(num5,num6)))));
		}
	}
	fclose (stdin);
	fclose (stdout);
	return 0;
} 
