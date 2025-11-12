#include<bits/stdc++.h>
using namespace std;
const int M = 1e5;
int Ma(int a,int b,int c){
	if(a>=b){
		if(a>=c){
			return 1;
		}
		else{
			return 3;
		}
	}
	else{
		if(b>=c){
			return 2;
		}
		else{
			return 3;
		}
	}
}
int Middle(int a,int b,int c){
	if(a>=b){
		if(b>=c){
			return 2;
		}
		else{
			if(a>=c){
				return 3;
			}
			else{
				return 1;
			}
		}
	}
	else{
		if(a>=c){
			return 1;
		}
		else{
			if(b>=c){
				return 3;
			}
			else{
				return 2;
			}
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int d1,d2,d3,n1,n2,n3;
	vector<int>club(M);
	vector<int>Max(M);
	vector<int>Mid(M);
	vector<int>Maxd(M);
	vector<int>Midd(M);
	int t,n;
	cin>>t;
	vector<int>ans(t);
	for(int i = 0;i<t;i++){
		cin>>n;
		d1 = d2 = d3 = n1 = n2 = n3 = 0;
		for(int j = 0;j<3*n;j+=3){
			cin>>club[j]>>club[j+1]>>club[j+2];
			if(Ma(club[j],club[j+1],club[j+2]) == 1){
				Max[j/3] = club[j];
				Maxd[j/3] = 1;
			}
			else if(Ma(club[j],club[j+1],club[j+2]) == 2){
				Max[j/3] = club[j+1];
				Maxd[j/3] = 2;
			}
			else{
				Max[j/3] = club[j+2];
				Maxd[j/3] = 3;
			}
			if(Middle(club[j],club[j+1],club[j+2]) == 1){
				Mid[j/3] = club[j];
				Midd[j/3] = 1;
			}
			else if(Middle(club[j],club[j+1],club[j+2]) == 2){
				Mid[j/3] = club[j+1];
				Midd[j/3] = 2;
			}
			else{
				Mid[j/3] = club[j+2];
				Midd[j/3] = 3;
			}
		}
		for(int j = 0;j<n-1;j++){
			for(int k = 0;k<n-j-1;k++){
				if (Max[k]-Max[k+1]<Mid[k]-Mid[k+1]){
					int a = Max[k];
					Max[k] = Max[k+1];
					Max[k+1] = a;
					a = Maxd[k];
					Maxd[k] = Maxd[k+1];
					Maxd[k+1] = a;
					a = Mid[k];
					Mid[k] = Mid[k+1];
					Mid[k+1] = a;
					a = Midd[k];
					Midd[k] = Midd[k+1];
					Midd[k+1] = a;
				}
			}
		}
		int c = 0;
		while(c<n){
			if(n1>=n/2&&Maxd[c] == 1){
				if(Midd[c] == 2){
					n2+=1;
					d2+=Mid[c];
				}else{
					n3+=1;
					d3+=Mid[c];
				}
			}
			else if(n2>=n/2&&Maxd[c] == 2){
				if(Midd[c] == 1){
					n1+=1;
					d1+=Mid[c];
				}else{
					n3+=1;
					d3+=Mid[c];
				}
			}else if(n3>=n/2&&Maxd[c] == 3){
				if(Midd[c] == 1){
					n1+=1;
					d1+=Mid[c];
				}else{
					n2+=1;
					d2+=Mid[c];
				}
			}
			else if(Maxd[c] == 1){
				n1+=1;
				d1+=Max[c];
			}
			else if(Maxd[c] == 2){
				n2+=1;
				d2+=Max[c];
			}
			else if(Maxd[c] == 3){
				n3+=1;
				d3+=Max[c];
			}
			c++;
		}
		ans[i] = d1+d2+d3;
	}
	for(int i = 0;i<t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
