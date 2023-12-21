#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int GetPrority(char ch, bool inStack = 0) {
    if (ch == '#') return 0;
    if (ch == '$') return 1;
    if (ch == '+' || ch == '-') return 3;
    if (ch == '*' || ch == '/') return 4;
    if (ch == '(' && inStack == true) return 2;
    if (ch == '(' && inStack == false) return 8;
    if (ch == ')' && inStack == true) return 8;
    if (ch == ')' && inStack == false) return 2;
    return -1;
}

int main() {
    string expr = "";
    while (getline(cin, expr)) {
        stack<double> nums;
        stack<char> opers;
        string ans = "";
        expr += '$';
        opers.push('#');
        int sign = 1;
        for (int i = 0; i < expr.size(); i++) {
            if (expr[i] >= '0' && expr[i] <= '9') {
                double tmp = 0.0;
                //整数部分
                while (i < expr.size() && expr[i] >= '0' && expr[i] <= '9') {
                    tmp = tmp * 10 + expr[i] - '0';
                    i += 1;
                }
                //小数部分
                if (i < expr.size() && expr[i] == '.') {
                    unsigned int offset = 1;
                    double left = 0;
                    i += 1;
                    while (i < expr.size() && expr[i] >= '0' && expr[i] <= '9') {
                        left = left * 10 + expr[i] - '0';
                        i += 1;
                        offset *= 10;
                    }
                    tmp = tmp + left / offset;
                }
                tmp = tmp * sign;
                nums.push(tmp);
                i -= 1;
                sign = 1;
            }
            else if (expr[i] != ' ') {
                if (expr[i] == '-') {
                    if (i == 0 || expr[i - 2] < '0' || expr[i - 2] > '9') {
                        sign = -1;
                        continue;
                    }
                }
                if (expr[i] == '+') {
                    if (i == 0 || expr[i - 2] < '0' || expr[i - 2] > '9') {
                        sign = 1;
                        continue;
                    }
                }
                while (GetPrority(expr[i]) <= GetPrority(opers.top(), 1)) {
                    char oper = opers.top();
                    if (oper == '(') {
                        opers.pop();
                        break;
                    }
                    else {
                        double b = nums.top();
                        nums.pop();
                        double a = nums.top();
                        nums.pop();
                        opers.pop();
                        double tmp = 0.0;
                        if (oper == '+') tmp = a + b;
                        else if (oper == '-') tmp = a - b;
                        else if (oper == '*') tmp = a * b;
                        else tmp = a / b;
                        nums.push(tmp);
                    }
                }
                if (expr[i] != ')')
                    opers.push(expr[i]);

            }
        }
        if (!nums.empty()) {
            double ans = nums.top();
            if (ans == -0.0) ans = 0.0;
            printf("%.6lf\n", ans);
        }
    }
    system("pause");
    return 0;
}