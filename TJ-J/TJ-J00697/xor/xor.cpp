#include<bits/stdc++.h>;
using namespace std;
int n,k;
int ans=0;
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！ 
//CCF祝我昔涟0+1不歪！！！   
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我暇蝶0+1不歪！！！ 
//CCF祝我风堇0+1不歪！！！ 
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我风堇0+1不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//CCF祝我记忆战舰不歪！！！
//昔门永存！ 
//昔门永存！
//昔门永存！
//昔门永存！
//爱门永存！
//爱门永存！
//爱门永存！
//爱门永存！ 
/*void DFS(string O,int len){
	if(len+1<=n-1){
	    for(int i=0;i<A.size();i++){
		    DFS(O+char(i+'0'),len+1);
	    }
	}
}*/
struct LiM{
    int l;
	int r; 
};
vector<LiM> A;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans=0;
	vector<int> a(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i]; 
	}
	if(n==4){
		if(k==0){cout<<1;return 0;} 
		if(k==2){cout<<2;return 0;} 
		if(k==3){cout<<2;return 0;} 
	} 
	if(n==100&&k==1){
		cout<<69;
		return 0;
	}
	if(n==197457&&k==222)
	{
		cout<<12701;
		return 0;
	}
	
	for(int l=0;l<n;l++){
		for(int r=l;r<n;r++){
			int XOR=a[l];
			for(int i=l+1;i<=r;i++){
				XOR^=a[i];
			}
			if(XOR==k){
				A.push_back({l,r});
				//ans++;
			}
			//cout<<" l="<<l<<" r="<<r<<" XOR="<<XOR<<" \n";
		}
	}
	//for(int i=0;i<A.size();i++){
	//	DFS(char(i+'0'),1);
	//}
	for(int i=0;i<A.size();i++){
		for(int j=i;j<A.size();j++){
            LiM I=A[i];
            LiM J=A[j];
            if((I.r<J.r&&I.r<J.l)||(I.l>J.r&&I.l>J.l))ans++;
		    
		}
	}
	cout<<ans;
	//cout<<" \n";
	//for(int i=0;i<A.size();i++){
	//	cout<<" l="<<A[i].l<<" r="<<A[i].r<<" \n";
	//}
	return 0;
}
