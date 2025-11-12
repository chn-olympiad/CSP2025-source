#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in", "r", stdin);
    freopen("seat.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int R;
    vector<int> students(n*m);
    for (int i = 0; i < n*m; i++){
        cin >> students[i];
        if (i == 0){
            R = students[0];
        }
    }
    sort(students.begin(), students.end(), greater<int>());
    int index = 0;
    for (int i = 0; i < m; i++){
        if (i % 2 == 0){
            for (int j = 0; j < n; j++){
                if (students[index] == R){
                    cout << i+1 << " " << j+1 << "\n";
                    return 0;
                }
                else{
                    index++;
                }
            }
        }
        else{
            for (int j = n-1; j >= 0; j--){
                if (students[index] == R){
                    cout << i+1 << " " << j+1 << "\n";
                    return 0;
                }
                else{
                    index++;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

