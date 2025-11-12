#include<bits/stdc++.h>
using namespace std;
int n,arryi[10000005],arrer[10000005],arrs[1000005],sum = 0,sumyi = 0,sumer = 0,sums = 0,sumz = 0,ts = 0,ts2 = 0;
int pd2(int x,int y,int zx,int zy){
	if(x>y){
		if(zx+1>n/2){
			return 0;
		}else{
			return 1;
		}
	}else if(x<y){
		if(zy+1>n/2){
			return 1;
		}else{
			return 0;
		}
	}else{
		if(zx>zy){
			return 0;
		}else{
			return 1;
		}
	}
}
void pd1(int yi,int er,int san){
	if(yi>er){
		if(yi>san){
			if(sumyi+1>n/2){
				ts2 = sumer;
				sumer+=pd2(er,san,sumer,sums);
				sums+=pd2(san,er,sums,sumer);
				if(sumer>ts2){
					ts+=er;
				}else{
					ts+=san;
				}
			}else{
				sumyi++;
			ts+=yi;
			}
		}else{
			if(sums+1>n/2){
				ts2 = sumyi;
				sumyi+=pd2(yi,er,sumyi,sumer);
				sumer+=pd2(er,yi,sumer,sumyi);
				if(sumyi>ts2){
					ts+=yi;
				}else{
					ts+=er;
				}
			}else{
				sums++;
			ts+=san;
			}
		}
	}else{
		if(er>san){
			if(sumer+1>n/2){
				ts2 = sumyi;
				sumyi+=pd2(yi,san,sumyi,sums);
				sums+=pd2(san,yi,sums,sumyi);
				if(sumyi>ts2){
					ts+=yi;
				}else{
					ts+=san;
				}
			}else{
				sumer+1;
				ts+=er;
			}
		}else{
			if(sums+1>n/2){
				ts2 = sumyi;
				sumyi+=pd2(yi,er,sumyi,sumer);
				sums+=pd2(er,yi,sumer,sumyi);
				if(sumyi>ts2){
					ts+=yi;
				}else{
					ts+=er;
				}
			}else{
				sums+1;
				ts+=san;
			}
		}
		
	}
	
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int m;
		cin>>m;
		for(int j = 0;j<m+sum;j++){
			cin>>arryi[j]>>arrer[j]>>arrs[j];
			pd1(arryi[j],arrer[j],arrs[j]);
			sumz+=ts;
		
			ts = 0;
		} 
		cout<<sumz<<endl;
		sum+=m;
	}



	return 0;
}


