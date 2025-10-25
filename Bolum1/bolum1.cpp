#include <iostream>
#include <random>
#include <chrono>
using namespace std;

using Clock = std::chrono::high_resolution_clock;
using TimePoint = Clock::time_point;
using Duration = Clock::duration;

void first(int n) {
    double A[n];
    double S[n];
    for (int i = 0; i < n; i++) {
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution dist(0,99);
        A[i] = dist(gen);
    }
    TimePoint baslangic_zamani = Clock::now();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            S[i]+=A[j];
        }
    }
    TimePoint bitis_zamani = Clock::now();
    Duration gecen_sure_duration = bitis_zamani - baslangic_zamani;
    auto mikrosaniye_cinsinden = std::chrono::duration_cast<std::chrono::microseconds>(gecen_sure_duration);
    cout << "Ic ice for  "<< mikrosaniye_cinsinden << endl;
}
void second(int n) {
    double A[n];
    double S[n];
    for (int i = 0; i < n; i++) {
        random_device rd;
        mt19937_64 gen(rd());
        uniform_int_distribution dist(0,99);
        A[i] = dist(gen);
    }
    TimePoint baslangic_zamani = Clock::now();
    for (int i = 0; i < n; i++) {
        if (i>0) {
            S[i]+=A[i]+S[i-1];
        }else {
            S[i]+=A[i];
        }
    }
    TimePoint bitis_zamani = Clock::now();
    Duration gecen_sure_duration = bitis_zamani - baslangic_zamani;
    auto mikrosaniye_cinsinden = std::chrono::duration_cast<std::chrono::microseconds>(gecen_sure_duration);
    cout <<"Tek for icinde "<< mikrosaniye_cinsinden << endl;
}
int main() {
    int n[]={1000,5000,10000,50000,100000};
    for (int i = 0; i < 5; i++) {
        cout << n[i] <<" tane elemanli dizi icin."<< endl;
        first(n[i]);
        second(n[i]);
        cout<<"-----------------"<<endl;
    }
    return 0;
}
//(