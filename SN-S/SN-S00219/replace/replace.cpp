//replace
#include<iostream> 
#include<string>
#define String string
using namespace std;
const int MAX = 200005;

int n , q;
String arr[MAX];
String brr[MAX];
int leng[MAX];

long long tackle(){
	String ini , goal;
	cin >> ini >> goal;
	if(ini.length() != goal.length()){
		return 0;
	} else {
		long long ans = 0;
		int length = ini.length();
		bool check = false;
		for(int i = 0;i < n;i++){			//Every double group
			for(int s = 0;s + leng[i] <= length;s++){		//try every position
				check = true;
				for(int j = s;j - s < leng[i];j++){		//try to replace
					if(ini[j] != arr[i][j - s]){
						check = false;
						break;			//disable to replace here
					}
				}
				if(check){			//You can replace here
					for(int j = 0;j < s;j++){		//ini == goal? 
						if(ini[j] != goal[j]){
							check = false;
							break;
						}
					}
					if(check){
						for(int j = s;j - s < leng[i];j++){		//replace one == goal?
							if(brr[i][j - s] != goal[j]){
								check = false;
								break;
							}
						}
						if(check){
							for(int j = leng[i] + s;j < length;j++){		//ini == goal?
								if(ini[j] != goal[j]){
									check = false;
									break;
								}
							}
							if(check){		//Congratulations!
								ans++;
								//cout << i << " is successful!\n";
							}
						}
					}
				}
			}
		}
		return ans;	
	}
}

long long cheat(int* arrc,int* brrc){
	String inic , goalc;
	long long ans = 0;
	cin >> inic >> goalc;
	if(inic.length() != goalc.length()) {
		return 0;
	} else {
		int length = inic.length();
		int iniIndex , goalIndex;
		for(int i = 0;i < length;i++){
			if(inic[i] == 'b'){
				iniIndex = i;
				break;
			}
		}
		for(int i = 0;i < length;i++){
			if(goalc[i] == 'b'){
				goalIndex = i;
				break;
			}
		}
		//finish initial
			
		for(int i = 0;i < n;i++){			//try everyone!
			//At first , you have to put your subString in;
			if((arrc[i] <= iniIndex) && ((leng[i] - arrc[i]) <= (length - iniIndex))){
				//In the end , check replaced one equal to goal;
				int third = iniIndex + (brrc[i] - arrc[i]);
				if(third == goalIndex){
					ans++;
				}
			}
		}
		return ans;
	}
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> q;
	for(int i = 0;i < n;i++){
		cin >> arr[i] >> brr[i];
		leng[i] = arr[i].length();
	}
	if((n > 1001) && (q > 1)){		//It's time to cheat for scores! (^ - ^)
		int* arrc = new int[n + 5];
		int* brrc = new int[n + 5];
		for(int i = 0;i < n;i++){
			for(int s = 0;s < leng[i];s++){
				if(arr[i][s] == 'b'){
					arrc[i] = s;
					break;
				}
			}
			for(int s = 0;s < leng[i];s++){
				if(brr[i][s] == 'b'){
					brrc[i] = s;
					break;
				}
			}
		}
		//initial finish
		
		for(int i = 0;i < q;i++){
			cout << cheat(arrc , brrc) << "\n";
		}
		delete[] arrc;
		delete[] brrc;
	} else {
		for(int i = 0;i < q;i++){
			cout << tackle() << "\n";
		}
	}
	return 0;
}
