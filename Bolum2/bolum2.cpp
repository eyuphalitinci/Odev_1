#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using Clock = chrono::high_resolution_clock;
using TimePoint = Clock::time_point;
using Duration = Clock::duration;

bool binary_Search(const vector<int>& arr, int arananDeger) {
    int temp;
    int alt =0,ust=arr.size();
    TimePoint baslangic_zamani = Clock::now();
    for (int i = 0; i <arr.size(); i++) {
        temp = (ust+alt)/2;
        if (arr[temp] == arananDeger) {
            TimePoint bitis_zamani = Clock::now();
            Duration gecen_sure_duration = bitis_zamani - baslangic_zamani;
            auto mikrosaniye_cinsinden = std::chrono::duration_cast<std::chrono::microseconds>(gecen_sure_duration);
            cout << "Calisma suresi "<<" "<< mikrosaniye_cinsinden << endl;
            return true;
        }else if (arr[temp]>arananDeger) {
            ust = temp;
        }else {
            alt = temp;
        }
    }
    TimePoint bitis_zamani = Clock::now();
    Duration gecen_sure_duration = bitis_zamani - baslangic_zamani;
    auto mikrosaniye_cinsinden = std::chrono::duration_cast<std::chrono::microseconds>(gecen_sure_duration);
    cout << "Calisma suresi  "<< mikrosaniye_cinsinden << endl;
    return false;
}
int main() {
    vector<int> B;
    for (int i=1;i<=1024;i++) {
        B.push_back(i);
    }
    bool sonuc = binary_Search(B,1024);
    cout << sonuc<<endl;
    return 0;
}
