#include <iostream> 
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string s; cin>>s;
    map<char, int> map;
    char odd_char;
    int odd = 0;
    string result;

    for(char ch : s) {
        map[ch]++;
    }

    for (const auto& pair : map) {
        if(odd > 1) {
            break;
        }
        if(pair.second % 2 != 0) {
            odd_char = pair.first;
            odd++;
            continue;
        }
        
        int chars = pair.second / 2;
        result += string(chars, pair.first);
    }
    string inverse = result;
    reverse(inverse.begin(), inverse.end());
    if(odd > 1) {
        cout<<"NO SOLUTION"<<"\n";
    }
    else if(odd == 1) {
        result += string(map[odd_char], odd_char);
        result += inverse;

        cout<<result<<"\n";
    }

    else {
        result += inverse;

        cout<<result<<"\n";
    }

    return 0;
}