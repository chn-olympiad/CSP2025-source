#include<bits/stdc++.h>
using namespace std;
int t,n,ar[100010][4],br[100010][3],sr,lr[100010],cr[4],c,p;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cr[1]=0;
		cr[2]=0;
		cr[3]=0;
		sr=0;
		c=0;
		cin >> n;
		for(int i=0;i<n;i++){
			int maxs=0,mins=10000000,s=0;
			for(int z=1;z<=3;z++){
				cin >> ar[i][z];
				if(maxs<ar[i][z]){
					br[i][0]=z;
					maxs=ar[i][z];
				}
				mins=min(mins,ar[i][z]);
				s+=ar[i][z];
			}
			br[i][1]=maxs;
			br[i][2]=maxs-s+maxs+mins;
		}
		for(int i=0;i<n;i++){
			cr[br[i][0]]++;
			sr+=br[i][1];
		}
		if(cr[1]>cr[2]){
			if(cr[1]>cr[3]){
				p=1;
			}else{
				p=3;
			}
		}else{
			if(cr[2]>cr[3]){
				p=2;
			}else{
				p=3;
			}
		}
		for(int i=0;i<n;i++){
			if(br[i][0]==p){
				lr[c]=br[i][2];
				c++;
			}
		}
		sort(lr,lr+c);
		for(int i=0;i<=c-n/2-1;i++){
			sr-=lr[i];
		}
		cout << sr << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
