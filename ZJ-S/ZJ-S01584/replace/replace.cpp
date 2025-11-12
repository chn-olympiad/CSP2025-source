#include <bits/stdc++.h>
using namespace std;

	int outd = 0;
	int moveleft = 0;
	int moveright = 0;
	bool flag = true;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	scanf("%d",&n);
	scanf("%d",&q);
	
	vector<pair<string,string> > acplace(n);
	
	for (int i = 0;i < n;i++){
		string ind;
		cin >> ind;
		acplace[i].first = ind;
		cin >> ind;
		acplace[i].second = ind;
	}
	
		
	for (int i = 0;i < q;i++){
		string inr;
		string inl;
		cin >> inr;
		cin >> inl;
		
		
		for (int j = 0;j < (int)inr.size();j++){
			if(flag){
				if(inr[j] != inl[j]){
					moveleft = j;
					moveright = j;
					flag = false;
				}
			}else{
				if(inr[j] != inl[j]){
					moveright = j;
				}
			}
		}
		
		cout << moveleft << ' ' << moveright << endl;
		
		vector<char> removesite;
		vector<char> movesite;
		
		for (int j = moveleft;j <= moveright;j++){
			removesite.push_back(inr[j]);
			movesite.push_back(inl[j]);
		}
		
		flag = true;
		
		for (int j = 0;j < n;j++){
			for (int k = 0;k < (int)acplace.size();k++){
				if(acplace[n].first[k] == removesite[0]){
					for(int t = k;t < k + (int)removesite.size();t++){
						if(acplace[j].first[k] == removesite[t-k]) flag = true;
						else {
							flag = false;
							break;
						}
						if(acplace[j].second[k] == movesite[t-k]) flag = true;
						else{
							flag = false;
							break;
						}
					}
				}
				if(flag) outd++;
			}
		}

		printf("%d",outd);
		outd = 0;
				
		
		
	}
	
	
	
	
	return 0;
}

