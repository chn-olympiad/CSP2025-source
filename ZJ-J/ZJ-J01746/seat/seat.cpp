#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,id;
	bool operator < (const node &cnt) const {
		return x>cnt.x;
	}
};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<node> a;
	for(int i=0;i<n*m;i++){
		int x;
		cin>>x;
		node temp;
		temp.x=x,temp.id=i+1;
		a.push_back(temp);
	}
	sort(a.begin(),a.end());
	//for(int i=0;i<a.size();i++) cout<<a[i].x<<" "<<a[i].id<<endl;
	int x=1,y=1,way=0;
	bool flag=false;
	for(int i=0;i<a.size();i++){
		//cout<<x<<" "<<y<<endl;
		if(a[i].id==1){
			cout<<x<<" "<<y<<endl;
			break;
		}
		if(flag){
			x++;
			flag=false;
			continue;
		}
		if(!way){
			y++;
			if(y==n){
				way=1;
				flag=true;
			}
		}else{
			y--;
			if(y==1){
				way=0;
				flag=true;
			}
		}
	}
	return 0;
}
