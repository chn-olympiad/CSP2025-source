#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,t;
int bm[3];
struct myd{
	int ax,bx,cx,g1,g2,bm1,bm2;
};
myd m[N];
int mmax(int x){
	if(m[x].ax >m[x].bx &&m[x].ax >m[x].cx ){
		m[x].bm1 =1;
		return m[x].ax ;
	}
	else if(m[x].bx >m[x].cx ){
		m[x].bm1 =2;
		return m[x].bx ;
	}
	else{
		m[x].bm1 =3;
		return m[x].cx ;
	}
}
int mmin(int x){
	if(m[x].ax <m[x].bx &&m[x].ax <m[x].cx ){
		m[x].bm2=1;
		return m[x].ax ;
	}
	else if(m[x].bx <m[x].cx ){
		m[x].bm2=2;
		return m[x].bx ;
	}
	else{
		m[x].bm2=3;
		return m[x].cx ;
	}
}
bool cmp(int a,int b){
	return m[a].g1 >m[b].g1 ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		bm[1]=0;
		bm[2]=0;
		bm[3]=0;
		for(int i=0;i<n;i++){
			cin>>m[i].ax>>m[i].bx >>m[i].cx ;
			m[i].g1 =mmax(i)-mmin(i);
			if(m[i].ax !=mmax(i)&&m[i].ax !=mmin(i)){
				m[i].g2 =m[i].ax -mmin(i);
			}
			if(m[i].bx !=mmax(i)&&m[i].bx !=mmin(i)){
				m[i].g2 =m[i].bx -mmin(i);
			}
			if(m[i].cx !=mmax(i)&&m[i].cx !=mmin(i)){
				m[i].g2 =m[i].cx -mmin(i);
			}
			ans+=mmin(i);
			cout<<ans<<endl;
		}
		for(int i=0;i<n;i++){
			if(bm[m[i].bm1 ]<n/2){
				ans+=m[i].g1 ;
				bm[m[i].bm1 ]++;
			}
			else if(bm[m[i].bm2 ]<n/2){
				ans+=m[i].g2 ;
				bm[m[i].bm2 ]++;
			}
		}
		cout<<ans;
	}
	return 0;
}
