//SN-J01198 鱼馨月 西安市曲江第一学校
#include<bits/stdc++.h> 
using namespace std;
const int N=1e3;
int n,m,scr_r,ansc,ansr;
int cls[10][10],scr[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int sump=n*m;
	for(int i=1;i<=sump;i++){
		cin>>scr[i];
		if(i==1) scr_r=scr[i];
	}
	if(scr_r=1){
		if(m%2==1){
			cout<<m<<" "<<n;
			return 0;
		}
		if(m%2==0){
			cout<<m<<" "<<1;
			return 0;
		}
	}
	sort(scr+1,scr+sump+1);
	int k=1,lsj;
	for(int i=1;i<=m;i++){
		k++;
		for(int j=1;j<=n;j++){
			if(i==1 && j==2) j--;
			if(j==n) i++,k++;
			if(j==1 && i!=1) continue;
			if(i%2==1){
				j++,k++;
			}
			if(i%2==0){
				j--,k++;
			}
			cls[i][j]=k;
			lsj=j;
			if(i==m && j==n) break;
		}
		if(scr[k]==scr_r){
			ansc=i,ansr=lsj;
			cout<<ansc<<" "<<ansr;
			return 0;
		}
	}
	return 0;
}
//seat 
