#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int n,m,n1,m1,a,j,i,x1[10000][10000],x[10000],z,f,g;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	cin>>a;
	x[0]=a;
	for(int i=1;i<z;i++){
		cin>>x[i];
	}
	sort(x,x+z,cmp);
	for(int i=0;i<z;i++){
		q.push(x[i]);
	}
	for(;i<m;i++){
		for(;;){
			if(f==0){
				if(j!=n-1){
					x1[j][i]=q.front();
					if(q.front()==a){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					j++;
					q.pop();
				}
				else{
					x1[j][i]=q.front();
					if(q.front()==a){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					q.pop();
					f=1;
					
					break;
				}
			}
			else{
				if(j!=0){
					x1[j][i]=q.front();
					if(q.front()==a){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					j--;
					q.pop();
				}
				else{
					x1[j][i]=q.front();
					if(q.front()==a){
						cout<<i+1<<" "<<j+1;
						return 0;
					}
					f=0;
					q.pop();
					
					break;
				}
			}
		}
	}
	return 0;
}
