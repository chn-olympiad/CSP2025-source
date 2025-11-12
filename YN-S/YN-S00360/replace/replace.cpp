#include<bits/stdc++.h>
using namespace std;
struct pairr{
	string a;
	string b;
};
int main(){
	ifstream cin("replace3.in");
	ofstream cout("replace.out");
	int n,k;
	cin>>n>>k;
	pairr *rep=new pairr[n];
	for(int i=0;i<n;i++){
		cin>>rep[i].a>>rep[i].b;
	}
	for(int i=0;i<k;i++){
		string source,target;
		cin>>source>>target;
		int sum=0;
		for(int j=0;j<n;j++){
			long l=source.find(rep[j].a);
			if(l!=0){
				if(l!=-1){
					string tmp=source;
					tmp.replace(l,l,rep[j].b);
					if(tmp==target){
						sum++;
					}
				}
			}
			if(l==0){
				if(l!=-1){
					string tmp=source;
					tmp.replace(l,l+rep[j].b.length(),rep[j].b);
					if(tmp==target){
						sum++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
}
