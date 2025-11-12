#include<bits/stdc++.h>
using namespace std;
struct as{
	long long  n;
	long long  b;
	long long  f;
}d[100000];
int main(){
//	freopen("club.in","r",stdin);
//	freopen("club.out","w",stdout);
	int t,n,minb,maxr,middle;
	cin>>t;
	int cnt1,cnt2,cnt3,id,id2,id3,cn1,cn2,cn3;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>d[i].n>>d[i].b>>d[i].f;
				if(d[i].n<d[i].b<d[i].f){
			minb=d[i].n;//nfb
			id=1;
			maxr=d[i].f;
			id2=3;
			middle=d[i].b;
			id3=2;
		}
		else if(d[i].n>d[i].b>d[i].f){
			minb=d[i].f;//fnb
			id=3;
			maxr=d[i].n;
			id2=1;
			middle=d[i].b;
			id3=2;
		}
		else if(d[i].b<d[i].n<d[i].f){
			minb=d[i].b;//bfn
			id=2;
			maxr=d[i].f;
			id2=3;
			middle=d[i].n;
			id3=1;
		}
		else if(d[i].b<d[i].f<d[i].n){
			minb=d[i].b;//bnf
			id=2;
			maxr=d[i].n;
			id2=1;
			middle=d[i].f;
			id3=3;
		}
		else if(d[i].n<d[i].f<d[i].b){
			minb=d[i].n;//nbf
			id=1;
			maxr=d[i].b;
			id2=2;
			middle=d[i].f;
			id3=3;
		}
		else if(d[i].f<d[i].n<d[i].b){
			minb=d[i].f;//fbn
			id=3;
			maxr=d[i].b;
			id2=2;
			middle=d[i].n;
			id3=1;
		}
		int y=n/2;
		if(cnt1<y){
			if(id2==1){
				cn1+=d[i].n;
				cnt1++;	
			} 
			else if(id2==2){
				cn1+=d[i].b;
				cnt1++;
			}
			else if(id2==3){
				cn1+=d[i].f;
				cnt1++;
			}
		}
		else if(cnt2<y){
			if(id2==1){
				cn2+=d[i].n;
				cnt2++;	
			} 
			else if(id2==2){
				cn2+=d[i].b;
				cnt2++;
			}
			else if(id2==3){
				cn2+=d[i].f;
				cnt2++;
			}
		}
		if(cnt3<y){
			if(id2==1){
				cn3+=d[i].n;
				cnt3++;	
			} 
			else if(id2==2){
				cn3+=d[i].b;
				cnt3++;
			}
			else if(id2==3){
				cn3+=d[i].f;
				cnt3++;
			}
		}
		}
	
		cout<<cn1+cn2+cn3<<endl;
	}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0
	return 0;
} 
