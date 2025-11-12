#include <bits/stdc++.h>
using namespace std;
struct grop{
    int num;
    int w[4]={0,0,0,0};
    int value,mxn;
};
void sortf(grop x[] ,  int beg,int end){
    if(end-beg<2) return ;
    if(end-beg==2) {
        if (x[beg].value<x[beg+1].value)swap(x[beg],x[beg+1]);
        return ;
    }
    int l=beg,r=end-1;
    while(l<r){
        while(x[l].value>=x[beg].value&&l<end-1) l++;
        while(x[r].value<=x[beg].value&&r>beg) r--;
        if(l<r) swap(x[l],x[r]);
    }
    if(x[beg].value<x[r].value){
    	swap(x[beg],x[r]);
    	sortf(x,r+1,end);
    	sortf(x,beg,r);
	}
	else{
		sortf(x,beg+1,end);
	}
}
int main(){
	freopen("club.in","r",stdin); freopen("blub.out","w",stdin);
    int t;cin>>t;while(t--){
        int n;cin>>n;grop w[n+10];
        for(int i=1;i<=n;i++){
            cin>>w[i].w[1]>>w[i].w[2]>>w[i].w[3];
            int cho=1;
            if (w[i].w[2]>w[i].w[cho]) cho=2;
            if (w[i].w[3]>w[i].w[cho]) cho=3;
            w[i].mxn=cho;
            w[i].value=w[i].w[cho];
            w[i].num=i;
        }
        sortf(w,1,1+n); int tot[5]={0},score=0; tot[3]=0; tot[1]=0; tot[2]=0;
        for(int i=1;i<=n;i++){
            if(tot[w[i].mxn]<int(n/2)) {
                score+=w[i].value;
                tot[w[i].mxn]++;
            }
            else{
                int cho=1; if(cho==w[i].mxn) cho=2;
                for(int j=1;j<=3;j++) if(j!=w[i].mxn && w[i].w[j]>w[i].w[cho]) cho=j; 
                for(int j=i+1;j<=n;j++){
                	if (w[j].mxn==w[i].mxn){
                		int cho=1; if(cho==w[i].mxn) cho=2;
                		for(int k=1;k<=3;k++) if(k!=w[j].mxn && w[j].w[k]>w[j].w[cho]) cho=k; 
					}
				}
				w[i].mxn=cho;
                w[i].value=w[i].w[cho];
                sortf(w,i,n+1);
                i=i-1;
            }
        }
        cout<<score<<endl;
    }
    return 0;
}


