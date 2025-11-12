#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int main(){
	freopen("club.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	int a[N], b[N], c[N];
	int max[N], min[N], mid[N], xy[N];
	int t, n;
	int a1=0, b1=0, c1=0;
	cin>>t;
	int num=0;
	for(int i=0;i<t;i++){
		cin >> n;
		for(int j=0;j<n;j++){
			cin>>a[j]>>b[j]>>c[j];
			max[j]=a[j];
			if(max[j]<=b[j])
				max[j]=b[j];
			if(max[j]<=c[j])
				max[j]=c[j];
			min[j]=a[j];
			if(min[j]<=b[j])
				min[j]=b[j];
			if(min[j]<=c[j])
				min[j]=c[j];
			mid[j]=a[j]+b[j]+c[j]-max[j]-min[j];		
		}
		for(int j=0;j<n;j++){
			if(max[j]!=min[j] && max[j]!=mid[j] && mid[j]!=min[j]){
				if(max[j]==a[j])
					a1+=1;
				if(max[j]==b[j])
					b1+=1;
				if(max[j]==c[j])
					c1+=1;
			}
			
		}
		for(int j=0;j<n;j++){
			num+=max[j];
		}
	}
	for(int i=0;i<t;i++){
		cout<<num<<endl;
	}
		
	return 0;
}