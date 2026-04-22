#include <iostream>
#include <bitset>
using namespace std;
int main() {
    int n;
    cin >> n;

    string bin = bitset<32>(n).to_string();
    bin = bin.substr(bin.find('1') == string::npos ? 31 : bin.find('1'));
    cout << bin << endl;  
    cout << oct << n << endl;
    cout << hex << uppercase << n << endl;
    return 0;
}