#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	int a[15][15];
	int cj[105];
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}                        
	int human=cj[1];          
	sort(cj+1,cj+1+n*m,cmp);   
	int ls=1;
	int hs=1;
	int gl=1;;
	bool flag=1;
	for(int i=1;i<=n*m;i++){
	    a[hs][ls]=cj[i];
		if(a[hs][ls]==human){
			cout<<ls<<" "<<hs;
			return 0;
		}
		if(hs==n||hs==1&&i!=1){
			ls++;
			hs--;
			a[hs][ls]=cj[i];
			i++;
		    if(flag==1){
				gl=-1;
				flag=0;
			}
		    else{
				gl=1;
				flag=1;
			}
		}
		hs+=gl;
    }
    return 0;
}
