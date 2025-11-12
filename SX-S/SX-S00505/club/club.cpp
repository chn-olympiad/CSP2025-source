#include<bits/stdc++.h>
using namespace std;
int t,n,ida,idb,idc,A[5][100010],la,lb,lc,l;
struct node{
	int id,z;
}a[100010],b[100010],c[100010];
bool cmp(node p,node q){
	if(p.z==q.z) return p.id>q.id;
	else return p.z<q.z;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	l=la=lb=lc=0;
		for(int i=1;i<=100000;i++){
			a[i].id=a[i].z=0;
			b[i].id=b[i].z=0;
			c[i].id=c[i].z=0;
		}
    	cin>>n;
    	la=lb=lc=n/2;
    	for(int i=1;i<=n;i++){
    		cin>>A[1][i]>>A[2][i]>>A[3][i];
    		a[i].z=A[1][i];
			b[i].z=A[2][i];
			c[i].z=A[3][i];
    		a[i].id=b[i].id=c[i].id=i;
		}
		sort(a+1,a+n+1,cmp);
		sort(b+1,b+n+1,cmp);
		sort(c+1,c+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[j].id==i) ida=j;
				if(b[j].id==i) idb=j;
				if(c[j].id==i) idc=j;
			}
			if(ida==max(ida,max(idb,idc))){
				if(la!=0){
					l+=A[1][i];
					la--;
				}else if(idb==max(idb,idc)&&lb!=0){
					l+=A[2][i];
					lb--;
				}else if(ida==idb){
					if(a[ida].z>b[idb].z){
						l+=a[ida].z;
						la--;
					}else if(a[ida].z<b[idb].z){
						l==b[idb].z;
						lb--;
					}
				}else if(idb==idc){
					if(b[idb].z>c[idc].z){
						l+=b[idb].z;
						lb--;
					}else if(b[idb].z<c[idc].z){
						l==c[idc].z;
						lc--;
					}
				}else if(ida==idc){
					if(a[ida].z>c[idc].z){
						l+=a[ida].z;
						la--;
					}else if(a[ida].z<c[idc].z){
						l==c[idc].z;
						lc--;
					}
				}else{
					l+=A[3][i];
					lc--;
				}
			}else if(idb==max(ida,max(idb,idc))){
				if(lb!=0){
					l+=A[2][i];
					lb--;
				}else if(idc==max(ida,idc)&&lc!=0){
					l+=A[3][i];
					lc--;	
				}else if(ida==idb){
					if(a[ida].z>b[idb].z){
						l+=a[ida].z;
						la--;
					}else if(a[ida].z<b[idb].z){
						l==b[idb].z;
						lb--;
					}
				}else if(idb==idc){
					if(b[idb].z>c[idc].z){
						l+=b[idb].z;
						lb--;
					}else if(b[idb].z<c[idc].z){
						l==c[idc].z;
						lc--;
					}
				}else if(ida==idc){
					if(a[ida].z>c[idc].z){
						l+=a[ida].z;
						la--;
					}else if(a[ida].z<c[idc].z){
						l==c[idc].z;
						lc--;
					}
				}else{
					l+=A[1][i];
					la--;
				}
			}else{
				if(lc!=0){
					l+=A[3][i];
					lc--;
				}else if(ida==max(ida,idb)&&la!=0){
					l+=A[1][i];
					la--;
				}else if(ida==idb){
					if(a[ida].z>b[idb].z){
						l+=a[ida].z;
						la--;
					}else if(a[ida].z<b[idb].z){
						l==b[idb].z;
						lb--;
					}
				}else if(idb==idc){
					if(b[idb].z>c[idc].z){
						l+=b[idb].z;
						lb--;
					}else if(b[idb].z<c[idc].z){
						l==c[idc].z;
						lc--;
					}
				}else if(ida==idc){
					if(a[ida].z>c[idc].z){
						l+=a[ida].z;
						la--;
					}else if(a[ida].z<c[idc].z){
						l==c[idc].z;
						lc--;
					}
				}else{
					l+=A[2][i];
					lb--;
				}
			}
		}
		cout<<l<<"\n";
	}
    return 0;
}
