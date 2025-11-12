#include<bits/stdc++.h>
constexpr int N=5e5+2,ln=0x0d000721;
int n,k,a[N],ans;
int main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>n>>k;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans++;
			}
		}
	}else if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			if(a[i]==1 and a[i+1]==1){
				ans++,i++;
			}
		}
	}else{
		std::cerr<<"ciallo\n";
		int hide=0,accept=7,old=2,top1=1,m0NESY,niko,s1s1,s1mple,ZywOo;
		m0NESY=hide;
		niko=accept;
		s1s1=s1mple=old;
		ZywOo=top1;
		std::string hltv="WildRank";
		std::string _6657="Pig";
		std::string device="there was no human";
		
		std::string sakiko="bot";
		std::string anju="kawaii";
		std::string noa ="kawaii";
		std::string mako="kawaii";
		std::string nene="kawaii";
		std::cout<<42;
		return 0;
		//freopen("
		//"xor.ans"
	}
	std::cout<<ans;
}
//uid:942578 id:mOOOOONESY_hidden
/*
#include<bits/stdc++.h>
constexpr int N=5e5+2,ln=0x0d000721,ln2=0721;
int n,k,a[N],ans;
int main(){
	freopen("E:\\cspj\\down\\xor\\xor5.in","r",stdin),freopen("xor.out","w",stdout);
	std::ios::sync_with_stdio(0),std::cin.tie(0);
	std::cin>>n>>k;
	for(int i=1;i<=n;i++){
		std::cin>>a[i];
	}
	if(k){
		int i=1;
		while(i<=n){
			if(a[i]==k){
				ans++;i++;continue;
			}
			int x=a[i++];
			while(i<=n and x and x!=k and a[i]!=k){
				x^=a[i++];
			}
			if(x==0){
				continue;
			}
			if(x==k){
				ans++;
			}
			if(i<=n and a[i]==k){
				ans++,i++;
			}
		}
	}else{
		int i=1;
		while(i<=n){
			if(a[i]==0){
				ans++;i++;continue;
			}
			int x=a[i++];
			while(i<=n and x and a[i]){
				x^=a[i++];
			}
			if(x==0){
				ans++;
			}
			if(i<=n and a[i]==0){
				ans++,i++;
			}
		}
	}
	std::cout<<ans;
}
//uid:942578
*/
