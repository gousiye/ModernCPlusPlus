#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <ostream>

using namespace std;


// 从后往前存储数字的

class BigInteger {
public:
    vector<int> num;
    int len = 0;
    BigInteger() {}
    BigInteger(string& str);
    bool operator <= (const BigInteger& other) const;
    BigInteger operator - (const BigInteger& other);
    BigInteger operator / (const BigInteger& other);
    BigInteger operator % (const BigInteger& other);
    BigInteger& operator = (const BigInteger& other);
    friend ostream& operator << (ostream& out, const BigInteger& x);
};

BigInteger::BigInteger(string& str) {
    this->len = str.size();
    this->num.resize(str.size(), 0);
    for (int i = 0; i < str.size(); i++) {
        this->num[i] = str[str.size() - i - 1] - '0';
    }
}

BigInteger& BigInteger::operator = (const BigInteger& other) {
    this->len = other.len;
    this->num.clear();
    this->num.resize(this->len, 0);
    for (int i = 0; i < other.len; i++) {
        this->num[i] = other.num[i];
    }
    return *this;
}

ostream& operator << (ostream& out, const BigInteger& x) {
    for (int i = x.len - 1; i >= 0; i--) {
        out << x.num[i];
    }
    return out;
}

BigInteger BigInteger::operator - (const BigInteger& other) {
    BigInteger result;
    result.num = this->num;
    result.len = this->len;
    int borrow = 0;
    int i = 0;
    for (i; i < other.len; i++) {
        int number = this->num[i] - other.num[i] - borrow;
        if (number < 0) {
            number += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        result.num[i] = number;
    }
    while (i < this->len && borrow) {
        result.num[i] -= borrow;
        if (result.num[i] < 0) {
            result.num[i] += 10;
            borrow = 1;
        }
        else borrow = 0;
        i += 1;
    }
    while (result.len > 1 && result.num[result.len - 1] == 0) {
        result.len -= 1;
    }
    return result;
}

bool BigInteger::operator <= (const BigInteger& other) const {
    if (this->len > other.len)
        return false;
    else if (this->len < other.len)
        return true;
    else {
        for (int i = this->len - 1; i >= 0; i--) {
            if (this->num[i] > other.num[i])
                return false;
            if (this->num[i] < other.num[i])
                return true;
        }
    }
    return true;
}

// 直接用王道机试指南上的结构会更好，P111
BigInteger BigInteger::operator % (const BigInteger& other) {
    BigInteger remainder;
    BigInteger result;
    remainder.num.resize(1, this->num.back());
    remainder.len = 1;
    result.num.resize(this->len, 0);
    result.len = this->len;
    for (int i = this->len - 1; i >= 0; i--) {
        while (other <= remainder) {
            remainder = remainder - other;
            result.num[i] += 1;
        }
        if (i > 0) {
            if (!(remainder.len == 1 && remainder.num[0] == 0)) {
                remainder.num.push_back(0);
                for (int j = remainder.len - 1; j >= 0; j--) {
                    remainder.num[j + 1] = remainder.num[j];
                }
                remainder.len += 1;
            }
            remainder.num[0] = this->num[i - 1];
        }
    }
    while (remainder.len > 1 && remainder.num[remainder.len - 1] == 0) {
        remainder.len -= 1;

    }
    return remainder;

}


int main() {
    string stra;
    // string strb;
    // std::cin >> stra >> strb;
    // BigInteger a(stra);
    // BigInteger b(strb);
    // BigInteger c = a % b;
    // std::cout << c.len;

    while (std::cin >> stra) {
        if (stra[0] == '-') {
            continue;
        }
        BigInteger a(stra);
        bool flag = false;
        for (int i = 2; i <= 9; i++) {
            string tmp(1, i + '0');
            BigInteger b(tmp);
            BigInteger remainder = a % b;
            if (remainder.len == 1 && remainder.num[0] == 0) {
                std::cout << i << " ";
                flag = true;
            }
        }
        if (flag == false) {
            std::cout << "none";
        }
        std::cout << std::endl;
    }
    system("pause");
    return 0;
}