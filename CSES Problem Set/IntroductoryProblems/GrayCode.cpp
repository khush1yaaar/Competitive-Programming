#include <iostream> 
#include <vector>

using namespace std;

int main() {
    int n; cin>>n;

    vector<string> gray_code;
    gray_code.push_back("0");
    gray_code.push_back("1");

    for(int i = 2; i <= n; i++) {
        int size = gray_code.size();
        for(int i = size - 1; i >= 0; i--) {
            gray_code.push_back(gray_code[i]);
        }

        for(int i = 0; i < size; i++) {
            gray_code[i] = "0" + gray_code[i];
            gray_code[i + size] = "1" + gray_code[i + size];
        }
    }

    for(int i = 0; i < gray_code.size(); i++) {
        cout<<gray_code[i]<<"\n";
    }
    return 0;
}