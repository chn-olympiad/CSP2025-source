#include<bits/stdc++.h>
using namespace std;
const int mx=1e5+10;


struct nd{
	int v,i;
}d1[mx],d2[mx],d3[mx];

bool cmp1(nd a,nd b){
	return a.v>b.v;
}

int t,n,a[mx][4],ans;
bool a2=true,a3=true;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	
	while(t--){
		cin >>n;
		ans = 0;
		for(int i=0;i<n;i++){
			for(int j=1;j<=3;j++){
				cin >>a[i][j];
			}
			d1[i].v = a[i][1];
			d1[i].i = i;
			d2[i].v = a[i][2];
			d2[i].i = i;
			d3[i].v = a[i][3];
			d3[i].i=i;
			if(a[i][2]!=0&&a[i][3]!=0) a2=false;
			if(a[i][3]!=0) a3 = false;
		}
		if(a2){
			sort(d1,d1+n,cmp1);
			for(int i=0;i<n/2;i++){
				ans+=d1[i].v;
			}
		}else if(a3){
			sort(d2,d2+n,cmp1);
			sort(d1,d1+n,cmp1);
			int s=0,i=0,j=0;
			while(s<n/2){
				s++;
				if(d1[i].v>d2[j].v&&d1[i].i!=d2[j].i){
					ans+=d1[i].v;
					i++;
				}else if(d1[i].v<d2[j].v&&d1[i].i!=d2[j].i){
					ans+=d2[j].v;
					j++;
				}
			}
		}else{
		  //²»»á	
		}
		cout <<ans<<'\n';
	}
	
	
	
	return 0;
}
