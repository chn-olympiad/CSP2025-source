#include <bits/stdc++.h>

#define int long long
using namespace std;

int num[500000];

int xxor(int l,int r){
	int ans=num[l];
	for(int i=l+1;i<=r;i++){
		int num1=num[i];
		ans=ans^num1;
		
	}
	return ans;
}

int n,k;

struct XorAns{
	int l;
	int r;
	bool flag=false;
}xorAns[500000];


int b(XorAns a,XorAns b){
	
	return a.l<b.l;
}


//int maxAns(int l,int r){
//	sort(xorAns,xorAns+n,b);
//	int ans=0;
//	for(int i=l;i<=r;i++){
//		if(xorAns[i].flag==false){
//		
//			if(xorAns[i].l==xorAns[i].r||xorAns[i].l+1==xorAns[i].r){
//				ans++;
//				xorAns[i].flag=true;
//			}else{
//				int c=maxAns(xorAns[i].l,xorAns[i].r);
//				
//			}
//			//for(int j=0;j<)
//		}
//	}
//	
//	return ans;
//}

int ansXor(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		for(int j=i;j<=r;j++){
			int ansxor=xxor(i,j);
			if(ansxor==k){
				xorAns[ans].l=i;
				xorAns[ans].r=j;
				//cout<<i<<" "<<j<<" "<<ans;
				ans++;
				
			}
//			if(ansxor==k && j>i+1){
//				ans=ansXor(i,j);
//				if(ans<1){
//					ans=1;
//				}
//				
//			}else if(ansxor == k){
//				ans++;
//			}else{
//				ans+=0;
//			}
		}
		
	}
//	maxAns(l,r);
	return ans;
	
}


signed main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin>>n>>k;
	for(int i=0;i<n;i++){
		
		cin>>num[i];
	}
	int ans=ansXor(0,n-1);
	//cout<<xxor(1,3);
	
	cout<<ans;
	

//	for(int i=0;i<ans;i++){
//		
//		cout<<i<<"-- l:"<<xorAns[i].l<<" r:"<<xorAns[i].r<<"\n";
//	}
	return 0;
	
}
