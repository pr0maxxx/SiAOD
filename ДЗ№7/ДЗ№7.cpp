//Инфиксная -- Массив --	Преобразовать в постфиксную запись
#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_oper(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

bool is_operand(char x)
{
    return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
}
bool level_priority(char x, vector <char> stack)
{
    return ((stack.back() == '-' || stack.back() == '+') && (x == '*' || x == '/'));
}

void extract(vector <char>& stack, string& postfix, char x)
{
    if (x == '+' || x == '-') {
        while (stack.back() != '(') {
            postfix += stack.back();
            stack.pop_back();
            if (stack.empty()) break;
        }
        stack.push_back(x);
    }
    else {
        while (stack.back() != '(') {
            postfix += stack.back();
            stack.pop_back();
            if (stack.back() == '-' || stack.back() == '+') break;
        }
        stack.push_back(x);
    }
}

void extract_to(vector <char>& stack, string& postfix)
{
    while (stack.back() != '(') {
        postfix += stack.back();
        stack.pop_back();
    }
    stack.pop_back();
}
string infix_to_postfix(string infix)
{
    vector <char> stack;
    string postfix = "";
    char symbol;
    int i = 0;
    
    while (infix.size() > i) {
        symbol = infix[i];
        if (symbol == ' ') {
            infix.erase(0, 1);

            continue;
        };
        if (is_oper(symbol)) {
            if (stack.size() == 0 || stack.back() == '(') {
                stack.push_back(symbol);
            }
            else if (level_priority(symbol, stack)) {
                stack.push_back(symbol);
            }
            else {
                extract(stack, postfix, symbol);
            }
        }
        else if (symbol == '(') {
            stack.push_back(symbol);
        }
        else if (symbol == ')') {
            extract_to(stack, postfix);
        }
        else {
            postfix += symbol;
        }
        i++;
    }
    while (stack.size() != 0) {
        postfix += stack.back();
        stack.pop_back();
    }
    return postfix;
}

int main()
{
    string line;
    line = "a+b*c";
    cout << infix_to_postfix(line) << endl;
}
