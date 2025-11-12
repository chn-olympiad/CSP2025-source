#include <bits/stdc++.h>
using namespace std;

long long a[12][12],b[500];
long long cj,n,m,temp;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	
	freopen("set.in","r",stdin);
	freopen("set.out","w",stdout);
	
	cin>>n>>m;
	cin>>cj;
	b[1]=cj;
	for(int i=2;i<=n*m;i++){
		cin>>b[i];
	}
	
	sort(b+1,b+1+n*m,cmp);
	
	int id=2;
	int sx=1,sy=1;
	a[sx][sy]=b[1];
	if(a[sx][sy]==cj){
		cout<<sy<<" "<<sx<<endl;
		return 0;
	}
	
	for(int i=2;i<=n*m;i++){
		if(sx==n&&sy%2==1){
			sy++;
			a[sx][sy]=b[id];
			if(a[sx][sy]==cj){
				cout<<sy<<" "<<sx<<endl;
				break;
			}
			else{
				id++;
			}
			continue;
		}
		else if(sx==1&&sy%2==0){
			sy++;
			a[sx][sy]=b[id];
			if(a[sx][sy]==cj){
				cout<<sy<<" "<<sx<<endl;
				break;
			}
			else{
				id++;
			}
			continue;
		}
		else if(sy%2==0){
			sx--;
			a[sx][sy]=b[id];
			if(a[sx][sy]==cj){
				cout<<sy<<" "<<sx<<endl;
				break;
			}
			else{
				id++;
			}
			continue;
		}
		else{
			sx++;
			a[sx][sy]=b[id];
			if(a[sx][sy]==cj){
				cout<<sy<<" "<<sx<<endl;
				break;
			}
			else{
				id++;
			}
			continue;
		}
		a[sx][sy]=b[id];
		if(a[sx][sy]==cj){
			cout<<sy<<" "<<sx<<endl;
			break;
		}
		else{
			id++;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
