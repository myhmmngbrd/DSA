// DSA.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <random>
#include <windows.h>
#include <vector>
using namespace std;
 
class Data {
    int* data = nullptr;
    int min = 0, max = 0, length = 0;
    // 동적메모리 해제
    void clear() {
        if (data) {
            delete[] data;
            data = nullptr;
        }
        min = 0;
        max = 0;
        length = 0;
    }
public:
    Data() { }
    Data(int length, int num = 0) {
        init(length, num);
    }
    Data(int min, int max, int length) {
        randinit(min, max, length);
    }
    ~Data() {
        delete[] data;
    }
    // 지정된 숫자로 데이터 초기화
    void init(int length, int num = 0) {
        clear();
        this->length = length;
        data = new int[length];
        for (int i = 0; i < length; i++) { data[i] = num; }
    }
    // 임의의 숫자 집합으로 데이터 초기화
    void randinit(int min, int max, int length) {
        clear();
        this->min = min;
        this->max = max;
        this->length = length;

        std::random_device seed;
        std::mt19937 engine(seed());
        std::uniform_int_distribution<int> distribution(min, max);

        data = new int[length];
        for (int i = 0; i < length; i++) {
            data[i] = distribution(engine);
        }
    }
    int size() {
        return length;
    }
    // 데이터 검사, 나중엔 삭제
    void print() {
        if (data) {
            for (int i = 0; i < length; i++) {
                printf("%d ", data[i]);
            }
            printf("\n");
        }
        else {
            cout << "데이터가 존재하지 않습니다." << endl;
        }
    }
    int& operator[] (int index) {
        return *(data + index);
    }
    Data& operator= (Data& another) {
        clear();
        min = another.min;
        max = another.max;
        length = another.length;
        data = new int[length];
        for (int i = 0; i < length; i++) {
            data[i] = another.data[i];
        }
        return *this;
    }
};

class Algorithm {
    Data data;
    Data ini;
public:
    Algorithm() {
        data.randinit(0,50,20);
        ini = data;
        data.print();
    }
    void sort() {
        int tmp, min;
        for (int i = 0; i < data.size() - 1; i++) {
            min = i;
            for (int j = i + 1; j < data.size(); j++) {
                if (data[j] < data[min]) {
                    min = j;
                }
            }
            tmp = data[i];
            data[i] = data[min];
            data[min] = tmp;
        }
        data.print();
    }
};

class View {

};


int main() {
    Algorithm a;
    a.sort();
}

