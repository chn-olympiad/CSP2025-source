#include <bits/stdc++.h>
using namespace std;
int n;
int T;
struct node{
	int x,y,z;
}a[100005];
bool cmp1(node a,node b){
	return a.x>b.x;
}
int main(){
	
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int maxx=0;
	cin>>T;
	while(T--){
		cin>>n;
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y!=0||a[i].z!=0){
				flag=0;
			}
		}
		sort(a+1,a+1+n,cmp1);
		if(flag){
			int num=0;
			for(int i=1;i<=n/2;i++){
				num+=a[i].x;
			}
			cout<<num<<"\n";
			continue;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
