#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	vector<int> num(n);
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	queue< vector<int> > q;
	q.push({-1,-1});
	int ans=0;
	while(!num.empty()){
		vector<int>t=q.front();
		q.pop();
		if(t[0]==-1){
			t.clear(); 
		}
		t.push_back(num[num.size()-1]);
		q.push(t);
			
		if(t.size()>=3){
			int ma=-1,len=0;
			for(int i=0;i<t.size();i++){
				len+=t[i];
				ma=max(ma,t[i]);
			}
			if(len>ma*2){
				ans++;
			}
		}
		t.pop_back();
		if(t.size()==0){
			t.push_back(-1);
		}
		q.push(t);
		
		num.pop_back();
	}
	cout<<ans%224;
	return 0;
}
