#include<bits/stdc++.h>
using namespace std;
int cj[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int js=1;
	int lie=1;
	int hang=1;
	for(int i=1;i<=n*m;i++){
		if(cj[1]>cj[i]){
			js+=1;
		}
			cin>>cj[i];
	}
	if(js<=n){
		cout<<lie<<" "<<js;
	}
	int kg=0;
	int sum=0;
	if(sum<=js){
		for(int i=1;i<=n;i++){
		lie+=1;
		sum++;
			if(i=n&&kg=0&&lie<=m){
				for(i>=1;i-=2){
					if(i==0){
						lie+=1;
						kg=1;
						sum++;
					}
				}
			}
		
		}
		hang=i;
	}
	
	cout<<lie<<" "<<hang;
	
	return 0;
}
